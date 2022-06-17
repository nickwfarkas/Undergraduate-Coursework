P <- read.csv("PolyXY.csv")

for(i in 0:7)
{
  Model <- lm(P$y~P$x+I(P$x^i))
  print(i)
  print(AIC(Model))
}

S <- read.csv("SunFertYield.csv")

Prop <- S$Success/S$Total

Model3 <- glm(Prop~S$Sun+S$Fertilizer, binomial("logit"), weights=14)
length(Prop)
