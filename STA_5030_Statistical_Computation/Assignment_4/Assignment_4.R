#1
#a

X <- c(35,90,47,45,68,70,55)
Y <- c(21,8,16,14,11,12,10)

plot(X,Y,main="Question 1a",xlab="Income",ylab="Engel's Coefficient")

#b

Model <- lm(Y~X)

#c

X <- matrix(c(1,1,1,1,1,1,1,35,90,47,45,68,70,55), ncol=2) 
Y <- matrix(c(21,8,16,14,11,12,10), ncol=1)

Z <- solve((t(X) %*% X),diag(1,nrow=2))

print(Z %*% (t(X) %*% Y))

XY <- data.frame(x=X,y=Y)

func <- function(XY)
{
  Z <- solve((t(XY$x.2) %*% XY$x.2),diag(1,nrow=1))
  return(Z %*% (t(XY$x.2) %*% XY$y))
}

func(XY)

#d
optim(par = XY, fn=func, method="BFGS")

#2
#a
L <- iris$Sepal.Length[1:50]
W <- iris$Sepal.Width[1:50]
SetosaModel <- lm(L~W)

#b


CI <- predict(SetosaModel, int="c")
CI <- CI[order(W),]
PI <- predict(SetosaModel, int="p")
PI <- PI[order(W),]

plot(L~W)
abline(SetosaModel)
matlines(sort(W),CI)
matlines(sort(W),PI)

#3
#a
GDP <- read.csv(file = "GDPLiteracy.csv")
plot(GDP$GDPperCapita~GDP$LiteracyRate)
#The points are not in a linear relation

#b
plot(log(GDP$GDPperCapita)~GDP$LiteracyRate)

#c
GDPModel <- lm(log(GDP$GDPperCapita)~GDP$LiteracyRate)

GDPModel.Summary <- summary(GDPModel)

intercept <- GDPModel.Summary$coefficients[1,1]

slope <- GDPModel.Summary$coefficients[2,1]

TS <- GDPModel.Summary$coefficients[,3]

SD <- GDPModel.Summary$coefficients[,2]

#No because it is less than 0.05 different than zero

#d
plot(log(GDP$GDPperCapita)~GDP$LiteracyRate)
abline(GDPModel)
CI <- predict(GDPModel, int="c")
CI <- CI[order(GDP$LiteracyRate),]
PI <- predict(GDPModel, int="p")
PI <- PI[order(GDP$LiteracyRate),]
matlines(sort(GDP$LiteracyRate),CI)
matlines(sort(GDP$LiteracyRate),PI)

#e
plot(GDPModel$residuals)
abline(a=0,b=0)

#The residuals are more concentrated towards the line

#f
qqnorm(GDPModel$residuals)
#Yes

#g
#Country



