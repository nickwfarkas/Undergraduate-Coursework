#Randomly selected 6 groundhogs' weight (in pounds) are:
# 
# 7.1, 10.2, 8.3, 9.5, 7.7, 10.8.
# 
# Calculate the test statistic for the null hypothesis that the population mean weight is 8.6 pounds. Round the answer to the nearest hundredth.

DataSet <- c(7.1,10.2,8.3,9.5,7.7,10.8)

H0 <- 8.6

t <- (mean(DataSet)-H0)/(sd(DataSet)/sqrt(length(DataSet)))