library(neuralnet)
library(caret)

# Creating neural network model with all iris data
NN <- neuralnet(Species~., data=iris, hidden = c(5,3))

# Testing using the same iris data (BAD)
pred <- compute(NN, iris[,c(1,2,3,4)])

# Extracting the greatest probability of each data point from the network
pred.max <- data.frame()
for(i in 1:150)
{
  pred.max <- rbind(pred.max, which.max(pred$net.result[i,]))
}

# Changing numeric IDs to actual species name 
pred.max$X1L <- gsub(1,"setosa",pred.max$X1L)
pred.max$X1L <- gsub(2,"versicolor",pred.max$X1L)
pred.max$X1L <- gsub(3,"virginica",pred.max$X1L)

# Changes from character to factor
pred.final <- as.factor(pred.max$X1L)
actual <- iris[,5]

confusionMatrix(pred.final,actual)
