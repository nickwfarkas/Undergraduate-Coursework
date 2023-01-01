library(corrplot)
library(dplyr)
library(caTools)
library("MASS")
library(rpart)

# Checking Correlation

levels.data <- read.csv("levels_data.csv")
corrplot(cor(levels.data),method = "circle", col="red")
hist(levels.data$total_comp,col="red",main = paste("Total Compensation"))
pairs(levels.data,upper.panel = NULL,diag.panel = panel.hist)

# Removing Extreme outliers
levels.data.without.outliers <- levels.data[levels.data$total_comp < quantile(levels.data$total_comp,.75)+(1.5*IQR(levels.data$total_comp)) 
                                            & levels.data$total_comp > quantile(levels.data$total_comp,.25)-(1.5*IQR(levels.data$total_comp)),]
levels.data.without.outliers <- levels.data.without.outliers[levels.data.without.outliers$total_comp > 25000,]
hist(levels.data.without.outliers$total_comp,col="red",main = paste("Total Compensation"))

# Training and test set
sample <- sample.split(levels.data.without.outliers$total_comp, SplitRatio = 0.75)
levels.data.without.outliers.train <- subset(levels.data.without.outliers, sample == TRUE)
levels.data.without.outliers.test  <- subset(levels.data.without.outliers, sample == FALSE)

# Creating Normalized Data
levels.data.scaled <- levels.data.without.outliers
levels.data.scaled$title_median_salary <- scale(levels.data.scaled$title_median_salary)
levels.data.scaled$total_yrs_exp <- scale(levels.data.scaled$total_yrs_exp)
levels.data.scaled$company_yrs_exp <- scale(levels.data.scaled$company_yrs_exp)
levels.data.scaled$state_median_income <- scale(levels.data.scaled$state_median_income)

sample <- sample.split(levels.data.scaled$total_comp, SplitRatio = 0.75)
levels.data.scaled.train <- subset(levels.data.scaled, sample == TRUE)
levels.data.scaled.test  <- subset(levels.data.scaled, sample == FALSE)

# Distribution
hist(levels.data.without.outliers$total_comp)
hist(levels.data$total_comp)

# Linear model with raw data
linear.model <- lm(log(total_comp)~.,data=levels.data)
summary(linear.model)
plot(linear.model$residuals)
# stepAIC(linear.model,direction = "backward")
AIC(linear.model)

# Linear model with scaled data
linear.model <- lm(log(total_comp)~.,data=levels.data.scaled)
summary(linear.model)
plot(linear.model$residuals)
AIC(linear.model)

# Final Linear Model
linear.model <- lm(log(total_comp)~title_median_salary+total_yrs_exp+company_yrs_exp+pop_city_greater_65K+state_median_income+faang+Business,data=levels.data.scaled.train)
summary(linear.model)
plot(linear.model$residuals)
AIC(linear.model)
linear.model.pred <- predict(linear.model,levels.data.scaled.test[,c("total_comp","title_median_salary","total_yrs_exp","company_yrs_exp","pop_city_greater_65K","state_median_income","faang","Business")])
MAE(exp(linear.model.pred),levels.data.scaled.test$total_comp)
RMSE(exp(linear.model.pred),levels.data.scaled.test$total_comp)

# Gamma Regression

# Gamma with raw data
gamma.model <- glm(total_comp~.,family= Gamma(link = "log"),data = levels.data.without.outliers)
summary(gamma.model)
plot(gamma.model$residuals)
AIC(gamma.model)

# Remove features
stepAIC(gamma.model,direction = "both")
gamma.model <- glm(total_comp~title_median_salary+total_yrs_exp+company_yrs_exp+pop_city_greater_65K+state_median_income+faang,data = levels.data.without.outliers)
AIC(gamma.model)

# Final Gamma Model
gamma.model <- glm(total_comp~.,family= Gamma(link = "log"),data = levels.data.without.outliers.train)
AIC(gamma.model)
summary(gamma.model)
gamma.model.pred <- predict(gamma.model,levels.data.without.outliers.test[,c("total_comp","title_median_salary","total_yrs_exp","company_yrs_exp","pop_city_greater_65K","state_median_income","faang","Business","Engineering","Technology")])
MAE(exp(gamma.model.pred),levels.data.without.outliers.test$total_comp)
RMSE(exp(gamma.model.pred),levels.data.without.outliers.test$total_comp)

# Tree Regression
tree.model <- rpart(total_comp~.,data = levels.data.scaled.train)
plot(tree.model)
text(tree.model, cex = 1)
summary(tree.model)
plot(residuals(tree.model))
tree.pred <- predict(tree.model,levels.data.scaled.test)
MAE(tree.pred,levels.data.scaled.test$total_comp)
RMSE(tree.pred,levels.data.scaled.test$total_comp)

# Tree Regression Log
tree.model <- rpart(log(total_comp)~.,data = levels.data.scaled.train)
plot(tree.model)
text(tree.model, cex = .75)
summary(tree.model)
plot(residuals(tree.model))

tree.pred <- predict(tree.model,levels.data.scaled.test)
MAE(exp(tree.pred),levels.data.scaled.test$total_comp)
RMSE(exp(tree.pred),levels.data.scaled.test$total_comp)

# Ensemble Learning

lr = lm(log(total_comp)~.,data = levels.data.without.outliers.train) 
gm <- glm(total_comp~.,family= Gamma(link = "log"),data = levels.data.without.outliers.train)
tm <- rpart(log(total_comp)~.,data = levels.data.without.outliers.train)

boosted.model.pred <- ensemble_predict(levels.data.without.outliers.test[,c("title_median_salary","total_yrs_exp","company_yrs_exp","pop_city_greater_65K","state_median_income","faang","Business","Engineering","Technology")])
plot(custom.resid(boosted.model.pred,levels.data.without.outliers.test$total_comp))
MAE(boosted.model.pred,levels.data.without.outliers.test$total_comp)
RMSE(boosted.model.pred,levels.data.without.outliers.test$total_comp)

# Utility Functions

ensemble_prediction <- function(x){
  return(exp(mean(c(
        predict(lr,x),
        predict(gm,x),
        predict(tm,x)
        ))))
}

MAE <- function(y.pred, y.actual){
  return(sum(abs(y.pred-y.actual))/length(y.actual))
}

RMSE <- function(y.pred, y.actual){
  return(sqrt(sum((y.pred-y.actual)^2)/length(y.actual)))
}

custom.resid <- function(y.pred, y.actual){
  return(y.pred-y.actual)
}

ensemble_predict <- function(x){
  pred <- numeric(length(x[,1]))
  for(i in 1:length(x[,1])){
    pred[i] <- ensemble_prediction(x[i,])
  }
  return(pred)
}

panel.hist <- function(x, ...) {
  usr <- par("usr")
  on.exit(par(usr))
  par(usr = c(usr[1:2], 0, 1.5))
  his <- hist(x, plot = FALSE)
  breaks <- his$breaks
  nB <- length(breaks)
  y <- his$counts
  y <- y/max(y)
  rect(breaks[-nB], 0, breaks[-1], y, col = rgb(1, 0, 0, alpha = 0.5), ...)
  # lines(density(x), col = 2, lwd = 2) # Uncomment to add density lines
}
