library(tree)

model1 <- tree(Species~., data=iris)

plot(model1)
text(model1)

model2 <- prune.tree(model1,best=4)

plot(model2)
text(model2)

library(caTools)

sample <- sample.split(iris$Species, SplitRatio = 0.7)
train  <- subset(iris, sample == TRUE)
test   <- subset(iris, sample == FALSE)

library(rpart)
library(caret)

model3 <- train(Species~.,data=train,method="rpart",trControl = trainControl(method = "cv", number = 3))
model4 <- train(Species~.,data=train,method="rpart",trControl = trainControl(method = "cv", number = 5))
model5 <- train(Species~.,data=train,method="rpart",trControl = trainControl(method = "cv", number = 10))

model3.pred <- predict(model3,newdata = test)
confmx3 <- table(model3.pred, test$Species)
sum(diag(confmx3))/sum(confmx3)

model4.pred <- predict(model4,newdata = test)
confmx4 <- table(model4.pred, test$Species)
sum(diag(confmx4))/sum(confmx4)

model5.pred <- predict(model5,newdata = test)
confmx5 <- table(model5.pred, test$Species)
sum(diag(confmx5))/sum(confmx5)
