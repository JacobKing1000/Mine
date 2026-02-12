# Dimensions
dim(mtcars)
nrow(mtcars)
ncol(mtcars)

# Column names
names(mtcars)

# Median of mpg
cat("median", median(mtcars$mpg), "\n")

# Mode function
get_mode <- function(x) {
  unique_values <- unique(x)
  unique_values[which.max(tabulate(match(x, unique_values)))]
}

# Mode of gear
get_mode(mtcars$gear)

# Summary statistics
summary(mtcars$mpg)
summary(mtcars$cyl)

# Cylinder mode
cylinder <- mtcars$cyl
get_mode(cylinder)

# Frequency of cylinders
cylinder_freq <- table(mtcars$cyl)
print(cylinder_freq)

# Standard deviation
std_dev <- sd(mtcars$mpg)
print(std_dev)

# Variance and SD from variance
variance <- var(mtcars$mpg)
std_dev_from_var <- sqrt(variance)
print(std_dev_from_var)
print(variance)