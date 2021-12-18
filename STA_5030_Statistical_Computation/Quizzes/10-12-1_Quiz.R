#Calculate the degrees of freedom for Welch's t-test for the following two samples. Round the answer to the nearest tenth.
#X: 46, 52, 10, 50, 35, 74
#Y: 51, 30, 36, 38, 48

X <- c(46, 52, 10, 50, 35, 74)
Y <- c(51, 30, 36, 38, 48)

t.test(X,Y)