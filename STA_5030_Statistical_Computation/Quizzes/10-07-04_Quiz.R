# Implment a (two-sided) equal-variance two-sample t-test for following samples, and report the p-value.  Round the answer to the nearest thousandth.

A <- c(88, 112, 95, 123, 71, 83, 115, 131)
B <- c(101, 100, 94, 59, 61)

TVAR <- t.test(A,B, alternative = "two.sided", var.equal = TRUE)

TVAR