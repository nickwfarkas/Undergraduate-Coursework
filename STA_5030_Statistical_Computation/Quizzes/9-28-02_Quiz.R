#Suppose that f(x) is a probability density function of an F-random variable with degrees of freedom df = i, df = 5.
#By ploting f(.01), f(.02), f(.03), ... f(1) for i = 1,2,3...
#find the minimum integer i such that y= f(x) is not monotone

d <- numeric(100)

for(i in 1:100)
{
  d[i] <- df((i*.01),i,5)
}

plot(x=(1:100),y=d)

max(d[5:100])
which.max(d[5:100])

