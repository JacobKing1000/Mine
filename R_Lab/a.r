# Load the mtcars dataset
data(mtcars)

# Display the first few rows of the dataset
head(mtcars)

# Get a summary of the dataset structure and variable types
str(mtcars)

# List the names of the variables in the dataset
names(mtcars)

# Generate a summary statistics table for each variable
summary(mtcars)

# Plot the relationship between weight (wt) and miles per gallon (mpg)
plot(mtcars$wt, mtcars$mpg,
     main = "Relationship between weight and miles per gallon",
     xlab = "Weight (wt)",
     ylab = "Miles Per Gallon (mpg)",
     pch = 19,
     col = "blue")

# Calculate the correlation coefficient between weight and mpg
cor(mtcars$wt, mtcars$mpg)

# Fit a linear model to predict mpg based on weight
model <- lm(mpg ~ wt, data = mtcars)

# Display summary statistics for the model
summary(model)

# Extract coefficients from the model
coef(model)

# Add a regression line to the plot
abline(model, col = "red", lwd = 2)

# Create new data frame with different weights
new_data <- data.frame(wt = c(2.5, 3.0, 3.5))

# Use the model to predict mpg for the new data
predict(model, newdata = new_data)