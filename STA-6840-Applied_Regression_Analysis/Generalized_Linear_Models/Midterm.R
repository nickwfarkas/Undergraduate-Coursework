library(faraway)

# 1a

plot(lweight~lpsa, data = prostate)

summary(lweight~lpsa)

outliers <- function(x)
{
  which(x > quantile(x)[4] + 1.5*IQR(x) | x < quantile(x)[2] - 1.5*IQR(x))
}

outliers(prostate$lweight)
prostate$lweight[outliers(prostate$lweight)]

# 32

#1b

real <- lm(lpsa~lweight, data = prostate)
summary(real)
plot(real)


B1 <- cov(prostate$lweight,prostate$lpsa)/var(prostate$lweight)
B0 <- mean(prostate$lpsa) - B1 * mean(prostate$lweight)

model <- function(x){
  return((x*B1) + B0)
}

#1c

st.err <- function(x,y){
  mean.x <- mean(x)
  a <- (1/(length(y)-2))
  b <- sum((y - model(x))^2)
  c <- sum((x - mean.x)^2)
  return(sqrt(a*(b/c)))
}


st.err(prostate$lweight,prostate$lpsa)

t.score <- (B1)/st.err(prostate$lweight,prostate$lpsa)

pt(t.score, df=length(prostate$lweight)-2, lower.tail = FALSE)

# We reject the null hypothesis

#1d

#TODO

#1e

residuals <- prostate$lpsa - model(prostate$lweight)

leverage <- (1/length(prostate$lpsa))+(((prostate$lweight-mean(prostate$lweight))^2)/sum((prostate$lweight-mean(prostate$lweight))^2))

plot(leverage,residuals)

#1f

# Data with high leverage are observations that are more of an outlier and high in residual.

#1g
mse <- function(residuals){
  (1/length(y.actual))*sum((y.actual-y.pred)^2)
}

cooks.distance(real)

D <- (residuals^2)/((2*mse(model(prostate$lweight),prostate$lpsa)*(leverage/((1-leverage))^2)))
D <- mean(residuals^2)




#TODO

#1h

#TODO

#2a

wbca.data <- wbca

log.likelihood <- function(B) {
  -1*(exp(B[1] + (B[2]*mean(wbca.data$Adhes)))/(1+exp(B[1] + (B[2]*mean(wbca.data$Adhes)))))
}

#2b

par <- optim(c(3,4),log.likelihood)$par

#2c

#TODO

#2d

fit <- function(){
  return(par[1],par[2])
}

plot(wbca$Adhes,wbca$Class)
abline(par[2],par[1])

#2e

summary(glm(wbca.data$Class~wbca.data$Adhes), family = "binomial")
#3a

africa.cleaned <- africa

africa.cleaned["pollib"][is.na(africa["pollib"])] <- 3

africa.cleaned$pollib <- as.factor(africa.cleaned$pollib)

#3b

africa.cleaned$pctvote.NA <- ifelse(is.na(africa.cleaned$pctvote),1,0) 

africa.cleaned$pctvote[is.na(africa.cleaned$pctvote)] <- 0

#3c 

str(africa.cleaned)

# 3d

poisson.model <- glm(miltcoup~., family = "poisson", data = africa.cleaned)

#3e

new.poisson.model <- step(poisson.model, direction = "backward")
summary(new.poisson.model)

#3f

# for every class of 0 the expected number of military coups decreases by .018
# for every class of 2 the expected number of military coups decreases by -18

#3g

#TODO

#3h

test <- 1-pchisq(new.poisson.model$deviance, df=46)
# We cannot reject the null hypthesis that the saturated model is siginificantly better

#3i
help("anova.glm")
test.model <- glm(miltcoup~oligarchy+parties+numelec+pctvote.NA, family = "poisson", data = africa.cleaned)

anova(new.poisson.model, test = "Chisq")
anova(test.model, test = "Chisq")

deviance(new.poisson.model)
deviance(test.model)

# pollib significantly improved the fit of the model

#3j

new.poisson.model.dis <- glm(miltcoup~oligarchy+parties+numelec+pctvote.NA+pollib, family = "quasipoisson", data = africa.cleaned)
summary(new.poisson.model.dis)
summary(new.poisson.model)

# Some of the predictors become more significant such as pasrties, numelec,pctvote.NA