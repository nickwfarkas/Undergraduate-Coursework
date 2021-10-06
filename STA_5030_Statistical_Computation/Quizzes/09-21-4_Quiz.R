##The FG.csv data set includes daily stock market return (%) for Facebook and Google (i.e., Alphabet) since Facebook went public on May 2012.

# Calculate the proportion of days on which both Facebook and Google have a positive return. Round the answer to the nearest hundredth.
# D <- read.csv("FG.csv")

fgProportion <- function(D)
{
  s <- 0
  for(i in 1:nrow(D))
  {
    if(D[i,2] >= 0 && D[i,3] >= 0)
    {
      print("Yes")
      s <- s + 1
    }
  }
  
  return(s/nrow(D))
}

print(fgProportion(D))