data <- read.csv("Data11-17-2.csv")

Model <- lm(data$Y~data$X1+data$X2+data$X3+data$X4+data$X5+data$X6+data$X7+data$X8+data$X9)

step(Model)
