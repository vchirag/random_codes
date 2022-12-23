import numpy as np
from scipy.linalg import solve
import matplotlib.pyplot as plt


def f(x):
    factor = (np.exp(1))**2 / ((np.exp(1))**4 - 1)
    temp = np.exp(2 * x) - np.exp(-2 * x) + (x / factor)
    return factor * temp


x0 = 0
xmax = 1
y0 = 0
ymax = 2

h1 = 0.1
h2 = 0.05

n1 = int((xmax - x0) / h1)
n2 = int((xmax - x0) / h2)

# System as Ay = b

# Solution for h1

y = np.zeros(n1 - 1)
y = np.transpose(y)

A = np.zeros([n1 - 1, n1 - 1])

b = np.zeros(n1 - 1)
b = np.transpose(b)

x1 = np.zeros(n1 - 1)
x2 = np.zeros(n2 - 1)

for i in range(n1 - 1):
    x1[i] = x0 + (i + 1) * h1

for i in range(n1 - 1):
    if (i == 0):
        b[i] = -4 * h1**2 * x1[i] - y0
    elif (i == n1 - 2):
        b[i] = -4 * h1**2 * x1[i] - ymax
    else:
        b[i] = -4 * h1**2 * x1[i]

for i in range(n1 - 1):
    for j in range(n1 - 1):
        if i == j:
            A[i][j] = -2 - 4 * h1**2
        if j == i + 1:
            A[i][j] = 1
        if i == j + 1:
            A[i][j] = 1

y = solve(A, b)

plt.scatter(x1, y)
plt.plot(x1, f(x1), "k")
