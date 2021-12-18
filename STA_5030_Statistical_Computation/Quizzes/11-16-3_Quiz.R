abalone <- read.csv("abalone.csv")

cor(abalone$Rings,abalone$Length)

cor(abalone$Rings,abalone$Diameter)

cor(abalone$Rings,abalone$Height)

Model <- lm(abalone$Rings~abalone$Sex+abalone$Length+abalone$Diameter+abalone$Height)

summary(Model)
