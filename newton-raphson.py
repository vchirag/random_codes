# To use: Newton's method to solve x - 0.8 - 0.2 sinx within an accuracy of 0.0001 in an interval [0, pi/2]

import numpy as np


def func(x):
    temp = x - 0.8 - 0.2 * np.sin(x)
    return temp


def deriv(x):
    temp = 1 - 0.2 * np.cos(x)
    return temp


accuracy = 0.0001

# Initial guess of the root
x0 = 0.1
x1 = x0 - (func(x0) / deriv(x0))

# Computed error
error = np.abs((x1 - x0) / x1)

# A variable to check how many times the loop ran
ctr = 1

while error > accuracy:
    x0 = x1
    x1 = x0 - (func(x0) / deriv(x0))
    error = np.abs((x1 - x0) / x1)

    print("The value of the root after", ctr, "th iteration: ",
          x1, "with a relative error: ", error * 100, "%")
    ctr += 1
