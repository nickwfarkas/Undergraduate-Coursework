# Implement a (two-sided) Wilcoxon signed-rank test in R by using the "wilcox.test" funciton to see if the following sample has 𝜇=100
# 
# 114, 110, 130, 104, 86, 110, 129, 103, 82, 140, 126, 116, 109, 124, 94
# 
# Report the p-value. Round the answer to the nearest thousandth.
# 
# (Tips: Ignore the warning message. It appears because of ties. For example, 114 and 86 have the same rank if the signs are ignored.)

X <- c(114, 110, 130, 104, 86, 110, 129, 103, 82, 140, 126, 116, 109, 124, 94)

wilcox.test(X,mu=100,alternative = "two.sided")