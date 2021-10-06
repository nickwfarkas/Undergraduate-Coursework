# Below is the systolic blood pressure in mmHg of randomly selected 10 athletes:
#   
#   102.5, 100.0, 104.7, 89.8, 101.5, 104.5, 99.9, 94.1, 94.8, 97.2.
# 
# The sample mean is 98.9.
# 
# By using a resampling method with 10,000 iterations or more,
# 
# evaluate the standard error of the sample mean.
# 
# (A reasonable error margin is allowed, as the answer varies due to randomness.)

X <- c(102.5, 100.0, 104.7, 89.8, 101.5, 104.5, 99.9, 94.1, 94.8, 97.2)

M <- numeric(10000)

for(i in 1:length(M))
{
  M[i] <- mean(sample(X,replace=T))
}

sd(M)
