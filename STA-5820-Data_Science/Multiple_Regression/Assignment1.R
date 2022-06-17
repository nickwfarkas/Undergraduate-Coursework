#1a
par(mar=c(1, 1, 1, 1))
plot(beaver1$time,beaver1$temp)

#1b
B1 <- beaver1[(beaver1$time > 800 & beaver1$time < 1159),]

#1c
Model.B1 <- lm(B1$temp~B1$time)
summary(Model.B1)

#1d
Model.B1.Improved <- lm(B1$temp~B1$time+log(B1$time))
summary(Model.B1.Improved)

#If we sqrt the time the relationship improves seen in the R Squared Value

#2a
X <- c(0,.5,1,1.5,2,2.5,3)
Y <- c(0,.25,1,2.25,4,6.25,9)
Q2 <- data.frame(X,Y)

Model.Q2 <- lm(Q2$Y~Q2$X)
summary(Model.Q2)

#2b
par()
plot(Q2)
abline(Model.Q2, col="red")

#2c
plot(Q2$X, Model.Q2$residuals)

# The plot follows a quadratic relationship

#3a
Adv <- read.csv("Advertising.csv")
pairs(Adv[,c(5,2,3,4)])

#3b
Model.Adv <- lm(Adv$sales~Adv$TV)
summary(Model.Adv)
#Yes. P-Value is much less than .05 so we reject null hypothesis. There is a significant relationship
#YEs

#3c
plot(Adv$TV, Adv$sales)
abline(Model.Adv, col="red")

#3d
plot(Adv$TV,Model.Adv$residuals)
abline(h=0, col="blue")
#This does not satisfy IID.
#The variance is becoming greater over time

#3e
Model.Adv1 <- lm(Adv$sales~sqrt(Adv$TV))
Model.Adv2 <- lm(sqrt(Adv$sales)~Adv$TV)
Model.Adv3 <- lm(sqrt(Adv$sales)~sqrt(Adv$TV))

plot(Adv$TV,Model.Adv1$residuals)
abline(h=0, col="blue")

plot(Adv$TV,Model.Adv2$residuals)
abline(h=0, col="blue")

plot(Adv$TV,Model.Adv3$residuals)
abline(h=0, col="blue")

# The third and final scatter plot is better in terms of IID
# Not perfect but the variance is closer to 0 over time

#3f

plot(Adv$TV, Adv$sales)
abline(Model.Adv, col="red")
abline(Model.Adv3, col="green")

# The slope change captures more of the values than the last regression

