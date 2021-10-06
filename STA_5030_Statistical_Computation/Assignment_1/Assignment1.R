#Nicholas Farkas
#Assignment 1

#Question 1

library(matlib)
library(expm)

cat("Question 1\n\n")

x <- seq(0, 10, by=.01)

f <- function(x)
{
  return(sqrt(((x^3)+(3*(x^2))+1)/((x^4)+(5*(x^3))+7*(x)+9)))
}

PlotF <- function(x)
{
  plot(
    x,f(x),
    main = "Line graph of (x, f(x)) for 0 ≤ x ≤ 10 with increments of 0.01",
    type="l")
}

#(a)
cat("1a.See Graph Labeled Line graph of (x, f(x)) for 0 ≤ x ≤ 10 with increments of 0.01\n\n")
PlotF(x)

#(b)
cat("1b.\n\n")
fValues <- c(f(x))
maxFValue = max(fValues)
maximizer = x[which.max(fValues)]
print(paste("Max Value: ",maxFValue))
print(paste("Maximizer: ",round(maximizer,digits = 2)))
cat("\n")

#Question 2

set.seed(1)
x <- rnorm(1000)

cat("Question 2\n\n")

#(a)
cat("2a.\n\n")
s <- sd(x)
print(paste("Standard Deviation: ",s))

#(b)
cat("2b.\n\n")
oneHundreth <- sort(x)[100]
print(paste("100-th smallest number: ",oneHundreth))

#(c)
cat("2c.\n\n")
z <- (oneHundreth-mean(x))/s
print("Yes, the z-score is -1.31 after rounding, which gives an area of .09510 which falls in the 10th percentile")
cat("\n")

#Question 3

cat("Question 3\n\n")

#(a)
cat("3a.\n\n")
A <- cbind(c(.979,.147),c(.144,-.999))

print("A^2: ")
print(A%^%2)
cat("\n")

#(b)
cat("3b.\n\n")
print("A^8: ")
print(A%^%8)
cat("\n")

print("A^32: ")
print(A%^%32)
cat("\n")

print("A^1024: ")
print(A%^%1024)
cat("\n")

#(c)
cat("3c.\n\n")
print("A^1000: ")
print(A%^%1000)
cat("\n")

#(d)
cat("3d.\n\n")
e <- eigen(A)

print("Eigenvalues:")
print(e$values)
cat("\n")
print("Eigenvector:")
print(e$vectors)
cat("\n\n")

#(e)
cat("3e.\n\n")
D <- cbind(c(e$values[1],0),c(0,e$values[2]))
P <- cbind(c(e$vectors[1,1],e$vectors[1,2]),c(e$vectors[2,1],e$vectors[2,2]))
inverseP <- inv(P)
PDP <- P%*%(D^1000)%*%inverseP

print("A^1000: ")
print(PDP)




