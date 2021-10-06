#1
#Type ‘ChickWeight’ in R, then a dataset of 50 chicks’ weight data will appear. Each chick was measured multiple times so you can see the growth of chicks. Draw growth curves of chicks with Diet = 1 in one pane (there are 20 chicks with Diet 1, so there will be 20 growth curves in one pane). The horizontal axis is Time (age) and the vertical axis is weight.

CW <- ChickWeight[ChickWeight$Diet == 1,]

plot.new()
axis(1, at= c(0:25))
axis(2, at= c(0:350))
plot(CW$Time, CW$weight, type="l", ylab="Weight", xlab = "Age")

#2
#a) Sin(2pi) = 0

#b)
library(pracma)
approxByFiniteSum <- function(nValue)
{
  return(polyval(taylor(f= sin, x0= 0, n= nValue),2*pi))
}

print(approxByFiniteSum(1))
print(approxByFiniteSum(3))

#c)
e <- 1
n <- 1
i <- 0
s <- 0
x <- 2*pi
j <- 0
repeat
{
  i <- i + 1
  j <- (-1)^(i+1)*(x^n)/factorial(n)
  n <- n + 2
  s <- s + j
  e <- abs(sin(x)-s)
  if(e < .000001)
  {
    break
    print(i)
  }
}

#3

#a)
sampleMean <- function(X)
{
  n <- length(X)
  D <- matrix(0,ncol= n , nrow= 100)
  for(i in 1:100)
  {
    D[i,] <- sample(X, n, replace= T)
  }
  return(apply(D,1,mean))
}

#b)
SM <- sampleMean(c(8.5, 7.5, 9.6, 13.6, 7.5, 7.7, 6.1, 5.5, 8.9, 8.6))
print(SM)

#c)
print(sd(SM))

#4

D <- numeric(120)
count <- 0

for (i in -40:-26)
{
  for(j in 1:8)
  {
    D[1+count]<-round(pnorm(((i+1)/10)-((j-1)/100)),5)
    count<-count+1
  }
}

SND <- matrix(D,15,8,TRUE)
colnames(SND) <- (0:7)/100
rownames(SND) <- (-39:-25)/10
print(SND)
