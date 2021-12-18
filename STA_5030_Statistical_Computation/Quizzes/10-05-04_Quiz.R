# Suppose that the t-statistic of a two-sided one-sample t-test is -1.23.
# 
# The sample size is 12. Calculate the p-value of the t-statistic.

P.val <- 2*(1-pt(abs(-1.23),df=11))
P.val
