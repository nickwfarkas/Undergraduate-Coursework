# When the null hypothesis is 𝜇=10, calculate V (the sum of signed rank for positive deviations) for the following sample.
# 
# 16.4, 12.6, 8.1, 14.0, 14.5, 9.2, 10.6, 9.1, 14.9

X <- c(16.4, 12.6, 8.1, 14.0, 14.5, 9.2, 10.6, 9.1, 14.9)

wilcox.test(X, mu=10)

