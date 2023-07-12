# Gauss legendre integration  for
# 0.2 + 25x - 200x2 + 675x3 - 900x4 + 400x5
# from a = 0 to b = 0.8

from scipy.special import roots_legendre, eval_legendre


def integrand(x):
    return (0.2 + 25 * x - 200 * x**2 + 675 * x**3 - 900 * x**4 + 400 * x**5)


def gaussLegendre(n_point):
    roots, weights = roots_legendre(n_point)
    return roots, weights


n_point = 3
roots, weights = gaussLegendre(n_point)

a = 0
b = 0.8

t = (b - a) / 2 * roots + (a + b) / 2

result = (b - a) / 2 * integrand(t).dot(weights)

print("Gauss-Legendre integration for  0.2 + 25x - 200x2 + 675x3 - 900x4 + 400x5 from from a = 0 to b = 0.8 is: ", result)
