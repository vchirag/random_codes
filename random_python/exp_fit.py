# To perform an exponential fit and find a,b for y = a*exp(b*x)
# Y = A + bx, Y = ln(y), A = ln(a)
# x = [2, 4, 6, 8, 10]
# y = [4.077, 11.084, 30.128, 81.197, 222.62]

import matplotlib.pyplot as plt
import numpy as np


def a1Calculator(x, y, n):
    sum_xy = sum(x * y)
    sum_xx = sum(x * x)
    sum_x = sum(x)
    sum_y = sum(y)

    numerator = (n * sum_xy) - (sum_x * sum_y)
    denominator = n * (sum_xx) - (sum_x)**2

    return numerator / denominator


def a0Calculator(x, y, n):
    return (sum(y) / n - a1Calculator(x, y, n) * (sum(x) / n))


# Defining lists of x, y datapoints
x = np.array([2, 4, 6, 8, 10])
y = np.array([4.077, 11.084, 30.128, 81.197, 222.62])

n = len(x)

# Forced linear fit
Y_forced = np.log(y)

a0 = a0Calculator(x, Y_forced, n)
a1 = a1Calculator(x, Y_forced, n)

a = np.exp(a0)
b = a1

Y_computed = []

for i in range(n):
    Y_computed.append(a0 + a1 * x[i])

fig, ax = plt.subplots()
fig.set_figheight(4)
fig.set_figwidth(15)
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.xaxis.grid()
ax.yaxis.grid()

ax.scatter(x, y, color="green", label="data")
ax.plot(x, a * np.exp(b * x), label="fit", color="red")

ax.legend(loc='best')
