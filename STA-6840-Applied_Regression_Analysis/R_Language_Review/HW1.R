library(faraway)
P <- prostate

# a

pairs(P)

#b

library(corrplot)
corrplot(cor(P), is.corr = TRUE)

#c


summary(P.Linear.Model)

# For every 1 lcavol, the logarithm of prostate specific antigen increases by about .7 on average

#d

plot(P$lcavol,P$lpsa)
abline(P.Linear.Model,col="red")
text(lpsa ~lcavol, labels=rownames(prostate), data = 
       P)

#e

P.Linear.Model <- lm(P$lpsa~P$lcavol+P$svi)
plot(P.Linear.Model, which = 1)  
#If you add the predictor svi the residuals vs fitted have less of an relationship

#f
mx <- max(cooks.distance(P.Linear.Model))
cd.p <- cooks.distance(P.Linear.Model)
cd.p
P[96,]


# That one point is pulling the regression line up a bit affecting its generalization

#g

P.Multi.Linear.Model <- lm(lpsa~lcavol+svi+gleason, data = P)
summary(P.Multi.Linear.Model)

# For every 1 gleason, the logarithm of prostate specific antigen increases by about .06057 on average

#h

t.test(P$lpsa, P$gleason, paired=TRUE)

#  From the linear model it does not significantly improve or ruin the model but gleason is a siginifcant predictor predictor o
