#1a

D <- c(3.1, 2.8, 4.0, 3.5, 3.3)
print((1/length(D))*sum(abs(D - mean(D))))

#1b
MAD <- function(D)
{
  n <- length(D)
  D <- abs(D - mean(D))
  return((1/n)*sum(D))
}

#1c
set.seed(123)
Y <- rnorm(100000)
MAD(Y)

#2

R <- read.csv(fileName,header = T)
M <- numeric(100)

for(i in 1:length(M))
{
  M[i] <- sd(sample(R$x,replace=T))
}

sd(M)

#3

TCOMPAREMEAN <- numeric(100)
TCOMPARESD <- numeric(100)
NCOMPAREMEAN <- numeric(100)
NCOMPARESD <- numeric(100)

for(i in 1:100)
{
  TRANDOM <- rt(10000,4)
  TCOMPAREMEAN[i] <- mean(TRANDOM)
  TCOMPARESD[i] <- sd(TRANDOM)
  
  NORMAL <- (rnorm(10000))/(sqrt((sum((rnorm(4))^2))/4))
  NCOMPAREMEAN[i] <- mean(NORMAL)
  NCOMPARESD[i] <- sd(NORMAL)
}

print("Average mean and standard deviation of rt")
mean(TCOMPAREMEAN)
mean(TCOMPARESD)

print("Average mean and standard deviation of rnorm")
mean(NCOMPAREMEAN)
mean(NCOMPARESD)