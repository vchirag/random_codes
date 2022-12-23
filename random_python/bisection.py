# To use the bisection method to solve f(x) = sqrt(x) - cos(x) on [0, 1]

import numpy as np


def func(x):
    temp = np.sqrt(x) - np.cos(x)
    return temp


x_lower = 0.2
x_upper = 0.7
x_root = 0

# A variable to check how many times the loop ran
ctr = 1


print("Initial guesses:\t x_lower:", x_lower, "\t", "x_upper: ", x_upper, "\n")

while (func(x_lower) * func(x_upper) < 0):
    x_root = (x_lower + x_upper) / 2

    if (func(x_lower) * func(x_root) < 0):
        #             x_lower = x_lower
        x_upper = x_root

    elif(func(x_lower) * func(x_root) > 0):
        x_lower = x_root
#             x_upper = x_upper

    elif(func(x_lower) * func(x_root) == 0):
        break

    print("The value of the root after", ctr, "th iteration: ", x_root)
    ctr += 1
