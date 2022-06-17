# The t-distribution has a heavier tail when its degrees of freedom is smaller.
# So the probability: P(t > 2) for n = 1, 2, 3, ... is a decreasing sequence of n
# where tn represents a t-random variable with df = n.
# What is the largest integer n such that P(t > 2) is larger than 0.05?

i <- 1

repeat
{
  current <- pt(q=2, df = i, lower.tail = F)
  if(current < .05)
  {
    print(i - 1)
    break
  }
  i <- i + 1
}