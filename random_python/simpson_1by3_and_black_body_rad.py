# Using Simpson's 1/3 Rule, show that:
# intg_0^(lambda_max){rho_T(lambda)dlambda} / intg_0^inf{rho_T(lambda)d(lambda)} ~ 1/4

import math
import scipy
from scipy import special
import numpy as np

PLANCK_CONSTANT = 6.62607015E-34
LIGHT_SPEED = 3E8
BOLTZMANN_CONSTANT = 1.380649E-23
PI = math.pi


def planckReturnerLambda(lambda_, temp):
    factor_1 = 8 * PI * PLANCK_CONSTANT * LIGHT_SPEED / (lambda_**5)
    factor_2 = math.exp(PLANCK_CONSTANT * LIGHT_SPEED /
                        (lambda_ * BOLTZMANN_CONSTANT * temp)) - 1
    return factor_1 / factor_2


def planckReturnerFrequency(frequency, temp):
    factor_1 = 8 * PI * PLANCK_CONSTANT * (frequncy**3) / (LIGHT_SPEED**3)
    factor_2 = math.exp(PLANCK_CONSTANT * frequency /
                        (BOLTZMANN_CONSTANT * temp)) - 1
    return factor_1 / factor_2

# Zero to infinity integral calculator
# Dimensionless integral while integrating rho(frequency)
# integral_0^inf{x^3 exp(x)/(exp(x) -1)}


def integrand(x):
    factor_1 = (x**3) * math.exp(x)
    factor_2 = math.exp(x) - 1
    return factor_1 / factor_2


def gaussLaguerre(n_point):
    roots, weights = scipy.special.roots_laguerre(n_point, mu=False)
    return roots, weights

# Returns the prefactor in Stefan's integration


def constantReturner(temp):
    factor_1 = 8 * PI * (BOLTZMANN_CONSTANT**4) * (temp**4)
    factor_2 = (LIGHT_SPEED**3) * (PLANCK_CONSTANT**3)
    return factor_1 / factor_2

# zero to lambda_max integral calculator

# test at T = 1000
# lower != 0 (division by zero not possible)


def simpson1by3(lower, upper, steps, temp):
    constants = planckReturnerLambda(
        lower, temp) + planckReturnerLambda(upper, temp)

    # step size
    h = (upper - lower) / steps

    # increment in even steps
    even_sum = 0

    # incrment in odd steps
    odd_sum = 0

    if (steps % 2 == 0):
        for i in range(1, steps, 2):
            odd_sum += planckReturnerLambda(lower + i * h, temp)
        for i in range(2, steps + 1, 2):
            even_sum += planckReturnerLambda(lower + i * h, temp)

    if (steps % 2 != 0):
        for i in range(1, steps + 1, 2):
            odd_sum += planckReturnerLambda(lower + i * h, temp)
        for i in range(2, steps, 2):
            even_sum += planckReturnerLambda(lower + i * h, temp)

    evaluated_integral = (
        (upper - lower) * (constants + 4 * odd_sum + 2 * even_sum)) / (3 * steps)

    return evaluated_integral


temp = list(range(1000, 6500, 500))
lambda_max = np.zeros(len(temp))
lambda_ = []
for i in np.arange(0.1, 3.1, 0.01):
    lambda_.append(i * (10**-6))

for index in range(len(temp)):
    #     print(temp[index])
    max_rho = 0
    max_wavelength = 0
    for wavelength in lambda_:
        if (max_rho <= planckReturnerLambda(wavelength, temp[index])):
            max_rho = planckReturnerLambda(wavelength, temp[index])
            max_wavelength = wavelength
#         print(max_wavelength)
#     print()
    lambda_max[index] = max_wavelength

for i in range((len(temp))):
    print("For T=", temp[i], ": ", "lambda_max = ", np.format_float_scientific(lambda_max[i], precision=3, exp_digits=2), "m , frequency_max = ", np.format_float_scientific(
        LIGHT_SPEED / lambda_max[i], precision=3, exp_digits=2), "Hz, ", "Wien's constant= ", np.format_float_scientific(lambda_max[i] * temp[i], precision=3, exp_digits=2))

# Order of quadrature

n_point = int(input("\nEnter the order of Gaussian-Laguerre quadrature: "))
roots, weights = gaussLaguerre(n_point)

sum_ = 0

# Returns the value of the dimensionless integral as pi^4/15
for i in range(n_point):
    sum_ += weights[i] * integrand(roots[i])

print()
# Approximate total power radiated (0 to infinity integration)
power = np.zeros(len(temp))
for i in range(len(temp)):
    print("Power radiated at T =", temp[i], ": ", np.format_float_scientific(constantReturner(temp[i]) * sum_, precision=3, exp_digits=2), "W/m^2",
          ", calculated Stefan's constant = ", np.format_float_scientific(constantReturner(temp[i]) * sum_ * (LIGHT_SPEED / 4) * (1 / (temp[i]**4)), precision=20, exp_digits=2), "W/m^2-K^4")

print("\nThe ratio of the power radiated from 0 to lambda_max and from 0 to infinity for: ")

for i in range(len(temp)):
    print("T=", temp[i], "is", np.format_float_scientific((simpson1by3(lambda_max[i] / 10,
                                                                       lambda_max[i], 100, temp[i]) / (constantReturner(temp[i]) * sum_)), precision=5, exp_digits=2))
