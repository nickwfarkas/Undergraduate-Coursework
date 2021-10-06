# The following Z gives 5 independent random numbers from a standard normal distribution. Make a chi-square random number with 5 degrees of freedom from this. Round the answer to the nearest hundredth.
# 
# > Z
# [1] -0.53 -1.88 0.01 0.15 -0.10

D <- c(-0.53, -1.88, 0.01, 0.15, -0.10)
C <- sum(D^2)
print(C)