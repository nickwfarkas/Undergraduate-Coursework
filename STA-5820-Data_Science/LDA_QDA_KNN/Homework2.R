
#a
Spec <- as.factor(c(rep("s",50),rep("e",50),rep("i",50)))
Spec <- factor(Spec, levels = c("s", "e", "i"))
# s for setosa; e for versicolor; i for virginica
iris <- cbind(iris[,1:4], Spec)
rm(Spec)
head(iris)

#b
pairs(iris, col = iris$Spec)

#c
library(MASS) # for lda
LDA <- lda(iris$Spec~iris$Petal.Length+iris$Petal.Width)

#d
LDA.predict.prob <- predict(LDA, type="repsonse")
LDA.predict$posterior

#e
LDA.predict <- predict(LDA, data.frame(iris$Petal.Length,iris$Petal.Width))
table(LDA.predict$class, iris$Spec)

#f
library(klaR) # for partimat
partimat(Spec~Petal.Length+Petal.Width, data = iris, method="lda")

#g
LDA2 <- lda(iris$Spec~iris$Petal.Length+iris$Petal.Width+iris$Sepal.Length+iris$Sepal.Width)

LDA2.predict.prob  <- predict(LDA2, type="repsonse")
LDA2.predict.prob$posterior

LDA2.predict <- predict(LDA2, data.frame(iris$Petal.Length,iris$Petal.Width))
table(LDA2.predict$class, iris$Spec)

partimat(Spec~Petal.Length+Petal.Width+Sepal.Length+Sepal.Width, data = iris, method="lda")

#h
QDA <- qda(iris$Spec~iris$Petal.Length+iris$Petal.Width)

QDA.predict.prob <- predict(QDA, type="repsonse")
QDA.predict.prob$posterior

QDA.predict <- predict(QDA, data.frame(iris$Petal.Length,iris$Petal.Width))
table(QDA.predict$class, iris$Spec)

partimat(Spec~Petal.Length+Petal.Width, data = iris, method="qda")

#i
library(class)
t <- cbind(iris$Petal.Length,iris$Petal.Width)
KNN <- knn(t, t, iris$Spec, k=10)
table(KNN, iris$Spec)
