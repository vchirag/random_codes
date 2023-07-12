# To construct the least square polynomial of order 1, 2, 3 for the given dataset

from scipy.linalg import solve
import numpy as np

x = np.array([4, 4.2, 4.5, 4.7, 5.1, 5.5, 5.9, 6.3, 6.8, 7.1])
y = np.array([102.56, 113.18, 130.11, 142.05, 167.53,
              195.14, 224.87, 256.73, 299.50, 326.72])

n = len(x)

order = int(input("Enter the order of the fitting polynomial: "))

powersOfX = []

for i in range(order + 1):
    powersOfX.append(x**i)

temp = []

for i in range(order + 1):
    temp.append(np.dot(x**i, y))

matrix_b = np.matrix(np.array(temp))
matrix_b.shape = (order + 1, 1)
matrix_b

temp = np.zeros((order + 1) * (order + 1))
matrix_a = np.matrix(np.array(temp))
matrix_a.shape = (order + 1, order + 1)

rows, cols = np.shape(matrix_a)

for i in range(rows):
    for j in range(cols):
        matrix_a[i, j] = sum(x**(i + j))

# print("Matrix A:\n", matrix_a, "\nMatrix B:\n", matrix_b)

unknowns = solve(matrix_a, matrix_b)

print("\nThe calculated fit is: ")
for i in range(order + 1):
    if i == order:
        print("%f" % ((unknowns[order - i])))

    else:

        if x[i] != 0.0:
            print("%f x**%d " % (x[i], order - i), end='')

            comp_y = []

for x_val in x:
    sum_ = 0
    for i in range(order + 1):
        sum_ += x**i * unknowns[i]
comp_y = sum_

print("\nx", "\t  y", "\t\t computed y")
for i in range(n):
    print(x[i], "\t ", y[i], "\t", comp_y[i])
