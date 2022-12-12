# To use fixed-point iteration method to determine a solution to within an accuracy of 0.01
# x^4 - 3x^2 - 3 = 0 on [1, 2]

import numpy as np


def func(x):
    factor = 3 * x**2 + 3
    return np.sqrt(np.sqrt(factor))


accuracy = 0.01

# Setting the initial values
x0 = 1.2
x1 = func(x0)

# A variable to check how many times the loop ran
ctr = 1

print("Initial guess :", x0, "\n")
while (np.abs(x1 - x0) > accuracy):
    x0 = x1
    x1 = func(x0)

    print("The value of the root after", ctr, "th iteration: ", x1)
    ctr += 1


print("\nThe root is: ", x1)
