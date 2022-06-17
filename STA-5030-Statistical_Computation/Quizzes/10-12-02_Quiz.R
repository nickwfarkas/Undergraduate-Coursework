#Calculate the p-value of the test for H0 that variance^2 of X = variance^2 of Y
#against H1 that variance^2 of X != variance^2 of Y

#X: 46, 52, 10, 50, 35, 74
#Y: 51, 30, 36, 38, 48

X <- c(46, 52, 10, 50, 35, 74)
Y <- c(51, 30, 36, 38, 48)

var.test(X,Y)

