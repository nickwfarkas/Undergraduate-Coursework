#What is the overall shape of a normal Q-Q plot for IID random numbers which
#follow a chi-square distribution with degrees of freedom 4? 

D <- rchisq(1000,df=4)

qqnorm(D)

