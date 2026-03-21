data(mtcars)
head(mtcars)
str(mtcars)
names(mtcars)
summary(mtcars)

plot(mtcars$wt, mtcars$mpg,
        main = "Relationship between weight and miles per gallon",
        xlab = "Weight (wt)",
        ylab = "Miles Per Gallon (mpg)",
        pch = 19,
        col = "blue")

cor(mtcars$wt, mtcars$mpg)
model <- lm(mpg ~ wt, data = mtcars)
summary(model)

coef(model)

abline(model, col = "red", lwd = 2)
new_data <- data.frame(wt = c(2.5, 3.0, 3.5))
predict(model, newdata = new_data)