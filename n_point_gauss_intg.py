# To find: intg_1^1.5(x**2*ln(x)) using n-point Gaussian quadrature

from scipy.special import roots_legendre
import numpy as np


def integrand(x):
    return x**2 * np.log(x)


def gaussLegendre(n_point):
    roots, weights = roots_legendre(n_point)
    return roots, weights


n_point = 2
roots, weights = gaussLegendre(n_point)

a = 1
b = 1.5

# Transformation of variables
t = ((b - a) / 2) * roots + (a + b) / 2

value = (b - a) / 2 * integrand(t).dot(weights)

print("The numerically calculated value of the integral is: ", value)
