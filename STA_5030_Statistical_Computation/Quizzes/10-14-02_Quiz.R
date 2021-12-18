LinearModel <- lm(mtcars$mpg ~ mtcars$hp)
plot(mtcars$mpg,mtcars$hp)
abline(LinearModel)
LinearModel$coefficients
