# 1
airquality

# a
aq <- na.omit(airquality)

# b
pairs(aq[,c(1,2,3,4)])

# c

cor(aq$Ozone, aq$Solar.R)
cor(aq$Ozone, aq$Wind)
cor(aq$Ozone, aq$Temp)
cor(aq$Solar.R, aq$Wind)
cor(aq$Solar.R, aq$Temp)
cor(aq$Wind, aq$Temp)

# d

MLR <- lm(aq$Ozone ~ aq$Solar.R + aq$Wind + aq$Temp)
summary(MLR)

# As Ozone Increases by 1 ppb, Solar Radiation increases by .06 lang,
# Tempurature increases by 1.65 degrees fahrenheit, and Wind decreases
# By 3.33 mph all the coefficients are significant falling well below .05

# e

MLR.S <- lm(aq$Ozone ~ aq$Solar.R)
MLR.W <- lm(aq$Ozone ~ aq$Wind)
MLR.T <- lm(aq$Ozone ~ aq$Temp)

plot(MLR.S$residuals)
plot(MLR.W$residuals)
plot(MLR.T$residuals)

# Each of the residual plots are roughly IID with no perceivable pattern

# f 

par(mfrow=c(2,2)) # this aligns four plots in 2 by 2 panes
plot(MLR)
par(mfrow=c(1,1))

# Near the end of the RvsF plot the there are a few outliers 
# bringing the regression line up if we eliminated the outliers
# That would significantly improve the model

# Same could be said about the Normal QQ Plot
# The observations are going at about a straight line
# But a few start to taper  off near the last Quantile

# Residuals vs leverage fits the data fairly well

# g 

MLR2 <- lm(Ozone ~ (Solar.R^2) + (Solar.R*Wind) + (Solar.R*Temp) + (Wind^2) + (Wind*Temp) + (Temp^2),data = aq)
summary(MLR2)

# h

AIC(MLR)

AIC(MLR2)

# Regression from part g is the better fit

# 2

# a

library(boot)

pairs(~time + factor(status) + sex + year + thickness, col=factor(melanoma$ulcer), data=melanoma)

# b

GLM <- glm(ulcer ~ time + status + sex + age + year + thickness,family=binomial, data=melanoma)
summary(GLM)

# The only predictor that passes the .05 significance level is thickness 
# but status and time are close to being significant.

# Higher thickness is associated with higher chance of ulceration

# c

step(GLM)

GLM2 <- glm(ulcer ~ time + status + thickness,family=binomial, data=melanoma)
summary(GLM2)

# With the removed predictors. The significance level of each predictor in each model improved.
# time is still slightly not significant

# d

GLM2.predict <- predict(GLM2, type="response")

c <- GLM2.predict > .5

t <- table(as.integer(c), melanoma$ulcer)

t

sum(diag(t))/sum(t)

# e 

correct.rate <- function(x,y){
  y2 <- (y > .5)
  TA <- table(x,y2)
  sum(diag(TA))/sum(TA)
}

correct.rate(melanoma$ulcer, GLM2.predict)

CV.err <- numeric(20)

for (i in 1:20)
{
  GLM.i <- glm(ulcer ~ time + status + thickness,family=binomial, data=melanoma)
  CV.err[i] <- cv.glm(melanoma$ulcer, GLM2, cost=correct.rate, K=10)
}

sd(CV.err)
mean(CV.err)

# f

library(MASS)
LDA <- lda(ulcer ~ time + status + thickness, data =melanoma)

LDA.Pred <- predict(LDA)

table(LDA.Pred$class , melanoma$ulcer)

# g
library(class)
m.train <- melanoma[(1:103),c(1,3,6)]
m.test <- melanoma[(104:205),c(1,3,6)]
KNN <- knn(m.train,m.test,melanoma$ulcer[1:103],k=10)
table(KNN,melanoma$ulcer[1:102])

# 3
library("readxl")
Default <- read_excel("default_of_credit_card_clients.xls")

# a

Model.Default <- glm(`default payment next month`~PAY_0,family=binomial, data=Default)

for (i in 1:11)
{
  print(i)
  print(AIC(glm(`default payment next month`~poly(PAY_0,i),family=binomial, data=Default)))
}

# 7 degrees

Model.Default <- glm(`default payment next month`~poly(PAY_0,7),family=binomial, data=Default)

# b

library(pROC)

Model.Default.pred <- predict(Model.Default,type="response")

auc(Default$`default payment next month`,Model.Default.pred)

# c
library(cvAUC)
cv.glm(Default$`default payment next month`,Model.Default, k=5)

# d
LDA.Default <- lda(`default payment next month`~poly(PAY_0,7), data=Default)
LDA.Default.pred <- predict(LDA.Default)
# e

auc(Default$`default payment next month`, as.numeric(LDA.Default.pred$class))

# f

cv.glm(Default$`default payment next month`,LDA.Default, k=5)

# g
LDA.Default2 <- lda(`default payment next month`~PAY_0+ PAY_2+ PAY_3+ PAY_4+ PAY_5+ PAY_6, data=Default)

cv.glm(Default$`default payment next month`,LDA.Default2, k=5)


