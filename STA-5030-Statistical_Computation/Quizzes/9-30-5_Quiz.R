#In the "mtcars" data set in the default R package, which of the following is most common?

help(mtcars)
xtabs(~vs+cyl,data=mtcars)
