#1

#a.
n <- 4
Z <- rnorm(10000)
X <- numeric(10000)
for(i in 1:n)
{
  X <- X + ((rnorm(10000))^2)
}

Tn <- Z/sqrt(X/n)

#b
percentile <- function(Tn, x)
{
  return(sort(Tn)[10000*x])
}

#c
cEstimate <- function(n, p)
{
  Z <- rnorm(10000)
  X <- numeric(10000)
  for(i in 1:n)
  {
    X <- X + ((rnorm(10000))^2)
  }
  Tn <- Z/sqrt(X/n)
  C <- percentile(Tn,p)
  return(C)
}

C <- replicate(1000,cEstimate(4,.025))

hist(C, seq(from=-3, to=-2.5, by=.01))

#d
theoreticalC <- qt(0.025,4) 

#2
MSFT <- read.csv("MSFT.csv")

DX <- log(MSFT$Close[2:length(MSFT$Date)])-log(MSFT$Close[1:length(MSFT$Date)])

print(paste("Mean: ",mean(DX)))
print(paste("Standard Deviation: ",sd(DX)))

#b
qqnorm(DX)

#We can conclude that this is not a normal distrubution due to the smallest and highest values deviating from the line and the middle being too thick.

#c

qqplot(qt(1:(length(DX))/length(DX),df=2),sort(DX))

qqplot(qt(1:(length(DX))/length(DX),df=4),sort(DX))

qqplot(qt(1:(length(DX))/length(DX),df=6),sort(DX))

#t6 distribution looks closest due to middle thickness and the beginning and ending deviations.

#3
set.seed(1014)

n <- 0
error <- .1
i <- 0

while(abs(error) >= .001)
{
  i <- i + 1
  n <- 2^i
  
  x <- runif(n)
  y <- runif(n)
  a <- (sum((((x^2)+(y^2))<=1))/n)
  
  error <- a-(pi/4)
}

print(paste("Final Sample Size: ",n))

#4

pprod <- function(P1,P2)
{
  if(length(P1) > length(P2))
  {
    g <- P1
    l <- P2
  }
  else
  {
    g <- P2
    l <- P1
  }
  
  M <- matrix(0,length(l),length(g)+(length(l)-1))

  for(i in 1:length(l)) 
  {
    P <- l[i]*g
    for(j in 1:(length(P)))
    {
      M[i,(i-1)+j] <- P[j]
    }
  }
  return(colSums(M))
}

pprod(pprod(c(1,1/sqrt(2),1/2),c(1,1/sqrt(3),1/3)),pprod(c(1,1/2,1/4),c(1,1/sqrt(5),1/5)))

