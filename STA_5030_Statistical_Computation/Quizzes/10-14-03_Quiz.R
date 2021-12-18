#Let 
# Y1 <- c(90,215,250,385)
# X1 <- c(1,1,1,1,10,20,30,40)
# Y <- matrix(Y1, nrow = 4, byrow=F)
# X <- matrix(X1, nrow = 4, byrow=F)

## What is the second element of ((X'X)^(-1))*(X'Y)

Y1 <- c(90,215,250,385)
X1 <- c(1,1,1,1,10,20,30,40)
Y <- matrix(Y1, nrow = 4, byrow=F)
X <- matrix(X1, nrow = 4, byrow=F)

Z <- solve(t(X)%*%X) %*% t(X) %*% Y


