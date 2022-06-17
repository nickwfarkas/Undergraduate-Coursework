library(neuralnet)
library(caTools)
library(plyr)
library(class)
library(caret)
library(pROC)
library(corrplot)
library(ggplot2)

# Data

setwd("~/Downloads/Data_Science/Final_Project")

NeedleDrop <- read.csv("NeedleDrop.csv")

NeedleDrop$artist <- as.factor(NeedleDrop$artist)

NeedleDrop$artist <- as.numeric(NeedleDrop$artist)

NeedleDrop <- NeedleDrop[,-1]

NeedleDrop[,1:14] <- scale(NeedleDrop[,-15])

NeedleDrop$rating <- as.character(NeedleDrop$rating)

NeedleDrop$rating[NeedleDrop$rating == '1'] <- "Good"

NeedleDrop$rating[NeedleDrop$rating == '0'] <- "Meh"

NeedleDrop$rating[NeedleDrop$rating == '-1'] <- "Not Good"

NeedleDrop$rating <- as.factor(NeedleDrop$rating)

anyNA(NeedleDrop)

split <- sample.split(NeedleDrop$rating, SplitRatio = 0.7)
NeedleDrop.Training <- subset(NeedleDrop,split == TRUE)
NeedleDrop.Test <- subset(NeedleDrop,split == FALSE)

ggplot(NeedleDrop, aes(x = rating)) + geom_bar()

# Model Neural Network

Model.NN <- neuralnet(rating~popularity+acousticness+danceability+
                        duration_ms+energy+instrumentalness+key+liveness+
                        loudness+mode+speechiness+tempo+valence,data=NeedleDrop.Training,
                        hidden=c(8), rep=5, err.fct = "ce", lifesign = "minimal", stepmax = 1e10,
                        linear.output = F, threshold = .001)

plot(Model.NN, rep = "best")


Model.NN.pred <- compute(Model.NN,NeedleDrop.Test)

idx <- apply(Model.NN.pred$net.result,1,which.max)

p <- c("Good", "Meh", "Not Good")[idx]

table(p, NeedleDrop.Test$rating)

# Random Forest

Model.RF <- train(rating~popularity+acousticness+danceability+
                     duration_ms+energy+instrumentalness+key+liveness+
                     loudness+mode+speechiness+tempo+valence,data=NeedleDrop.Training,
                   method="rf", trControl= trainControl(method="cv",number = 10),
                   preProcess = c("center","scale"), tuneLength = 20
                  )

plot(Model.RF)

Model.RF.pred <- predict(Model.RF,newdata = NeedleDrop.Test)

confusionMatrix(Model.RF.pred, NeedleDrop.Test$rating)

# KNN

Model.KNN <- train(rating~popularity+acousticness+danceability+
                     duration_ms+energy+instrumentalness+key+liveness+
                     loudness+mode+speechiness+tempo+valence,data=NeedleDrop,
                   method="knn", trControl= trainControl(method="cv",number = 10),
                   preProcess = c("center","scale"), tuneLength = 20
                 )

plot(Model.KNN)

Model.KNN.pred <- predict(Model.KNN,newdata = NeedleDrop.Test)

confusionMatrix(Model.KNN.pred, NeedleDrop.Test$rating)
