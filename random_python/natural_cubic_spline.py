# To construct natural cubc spline for the given data:
# x = [0.1, 0.2, 0.3, 0.4]
# y = [-0.62049958, -0.28398668, 0.00660095, 0.24842440]
# To approximate at x = 0.25

import numpy as np
import scipy
from scipy.linalg import solve


x = [0.1, 0.2, 0.3, 0.4]
y = [-0.62049958, -0.28398668, 0.00660095, 0.24842440]

n = len(x)
h = np.zeros(n - 1)

for i in range(n - 1):
    h[i] = x[i + 1] - x[i]

A = np.zeros([n, n])

X = np.array([[0, 0, 0, 0]])
X = np.transpose(X)

b = np.array([[0, 0, 0, 0]])
b = np.transpose(b)

# Constructing the A matrix
A[0][0] = 1
A[n - 1][n - 1] = 1

for i in range(1, n - 1):
    for j in range(0, n):
        if i == 1 and j == n - 1:
            pass
        elif i == 2 and j == 0:
            pass
        elif i == j:
            A[i][j] = 2 * (h[i - 1] + h[j])
        elif (i + j) == 3:
            A[i][j] = h[1]
        else:
            A[i][j] = h[i]

# Constructing the b matrix
for i in range(len(y)):
    if (i != 0) and (i != (n - 1)):
        b[i] = (3 / h[i]) * (y[i + 1] - y[i]) - \
            (3 / h[i - 1]) * (y[i] - y[i - 1])

c_constant = solve(A, b)
b_constant = []
d_constant = []

for i in range(len(c) - 1):
    b_constant.append((1 / h[i]) * (y[i + 1] - y[i]) -
                      (h[i] / 3) * (2 * c_constant[i] + c_constant[i + 1]))
    d_constant.append((1 / (3) * h[i]) * (c_constant[i + 1] - c_constant[i]))
