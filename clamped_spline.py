# Clamped Splines


import numpy as np
from scipy.linalg import solve
from scipy.special import roots_legendre


def integrand(x):
    return np.cos(x)


x = np.array([0, 0.25, 0.5, 0.75, 1.0])
a = []

for i in range(len(x)):
    temp = integrand(np.pi * x[i])
    a.append(temp)

# a values (given)
a = np.array(a)
a_coeff = np.delete(a, -1)

# h values
h = []
for i in range(1, len(x)):
    h.append(x[i] - x[i - 1])

# Defining the matrix A
a_mat = np.zeros([len(x), len(x)])

for i in range(len(x)):
    if i == 0 or i == (len(x) - 1):
        a_mat[i][i] = 2 * h[i - 1]
    else:
        a_mat[i][i] = 2 * (h[i - 1] + h[i])

        for j in range(i - 1, i + 2):
            if i < j:
                a_mat[i][j] = h[j - 2]
            elif i > j:
                a_mat[i][j] = h[j]
a_mat[0][1] = a_mat[1][0]
a_mat[len(x) - 1][len(x) - 2] = a_mat[len(x) - 2][len(x) - 1]


# Defining the column b
b_col = np.zeros(len(x))

for i in range(len(x)):
    if i == 0 or i == (len(x) - 1):
        b_col[i] = 0
    else:
        temp_1 = (3 / h[i]) * (a[i + 1] - a[i])
        temp_2 = (3 / h[i - 1]) * (a[i] - a[i - 1])
        b_col[i] = temp_1 - temp_2


# Solving for c coefficients
c_coeff = solve(a_mat, b_col)

# Solving for b and d coefficients
b_coeff = []
d_coeff = []

for i in range(len(x) - 1):
    temp_1 = (1 / h[i]) * (a[i + 1] - a[i])
    temp_2 = (h[i] / 3) * (c_coeff[i + 1] + 2 * c_coeff[i])
    b_coeff.append(temp_1 - temp_2)
    d_coeff.append((1 / (3 * h[i])) * (c_coeff[i + 1] - c_coeff[i]))


print("The coefficients are: ")
for i in range(len(a_coeff)):
    print("a[", i, "] = ", round(a_coeff[i], 7), "\t\tb[", i, "] = ", round(b_coeff[i], 7),
          "\t\tc[", i, "] = ", round(c_coeff[i], 7), "\t\td[", i, "] = ", round(d_coeff[i], 7))

print("---")
print("\n\nSplines for respective intervals: \n")

for i in range(4):
    if i == 0:
        print("Interval [0, 0.25]")
    if i == 1:
        print("Interval [0.25, 0.5]")
    if i == 2:
        print("Interval [0.5, 0.75]")
    if i == 3:
        print("Interval [0.75, 1.0]")
    print(round(a_coeff[i], 7), "+", round(b_coeff[i], 7), "* (x - ", x[i], ") + ", round(
        c_coeff[i], 7), "* (x - ", x[i], ")^2 + ", round(d_coeff[i], 7), "* (x - ", x[i], ")^3\n")

    # Spline integrals


def splines(a, b, c, d, x, x_point):
    return (a + b * (x - x_point) + c * (x - x_point)**2 + d * (x - x_point)**2)


def splines_first_derivative(b, c, d, x, x_point):
    return (b + 2 * c * (x - x_point)**1 + 3 * d * (x - x_point)**2)


def splines_second_derivative(c, d, x, x_point):
    return (2 * c + 6 * d * (x - x_point))


def gaussLegendre(n_point):
    roots, weights = roots_legendre(n_point)
    return roots, weights


n_point = 3
roots, weights = gaussLegendre(n_point)

integral_splines = []
for i in range(len(x) - 1):
    a = x[i]
    b = [x[i + 1]]
    t = (b - a) / 2 * roots + (a + b) / 2

    temp = np.round(
        (b - a) / 2 * splines(a_coeff[i], b_coeff[i], c_coeff[i], d_coeff[i], t, x[i]).dot(weights), 10)

    integral_splines.append(temp)

print("---")
print("The integral of the combined splines is: ", sum(integral_splines))

# Derivatives at x = 0.5
first_derivative_splines = []
second_derivative_splines = []

for i in range(len(x) - 1):
    temp = splines_first_derivative(
        b_coeff[i], c_coeff[i], d_coeff[i], 0.5, x[i])
    first_derivative_splines.append(temp)
    temp = splines_second_derivative(c_coeff[i], d_coeff[i], 0.5, x[i])
    second_derivative_splines.append(temp)

print("The first derivative of the spline at x = 0.5 is: ",
      first_derivative_splines[1])
print("The first derivative of the spline at x = 0.5 is: ",
      second_derivative_splines[1])
