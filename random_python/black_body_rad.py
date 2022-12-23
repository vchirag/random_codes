# Blackbody radiation curve
# rho_T(lambda) = (8pihc/lambda^5)*1/(exp(hc/lambdakT) - 1)dlambda
# 1. Write a function to obtan rho_T(lambda)
# 2. Obtain the value of lambda for which rho_T(lambda) is maximum
# 3. To calculate lambda_max at temp 1000-6000K in steps of 500K
# 4. Verify  Wien's displacement law

import math
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

# For verifying rho_T(lambda_max) = 170pi(kT)^5/(hc)^4


def analyticalExpression(temp):
    factor_1 = 170 * PI * ((BOLTZMANN_CONSTANT * temp)**5)
    factor_2 = (PLANCK_CONSTANT * LIGHT_SPEED)**4
    return factor_1 / factor_2

# Dimensionless integral one obtains while integrating rho(frequency)
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
    print("For T=", temp[i], ": ", "lambda_max = ", np.format_float_scientific(lambda_max[i], precision=3, exp_digits=2),
          "m , frequency_max = ", np.format_float_scientific(
              LIGHT_SPEED / lambda_max[i], precision=3, exp_digits=2), "Hz, ",
          "Wien's constant= ", np.format_float_scientific(
              lambda_max[i] * temp[i], precision=3, exp_digits=2),
          "m-K, rho_T(lambda_max)= ", np.format_float_scientific(planckReturnerLambda(
              lambda_max[i], temp[i]), precision=3, exp_digits=2), "W/m^3",
          ", Analytical Verification: ", np.format_float_scientific(analyticalExpression(temp[i]), precision=3, exp_digits=2), "W/m^3")
    print()

# Order of quadrature
n_point = int(input("Enter the order of Gaussian-Laguerre quadrature: "))
roots, weights = gaussLaguerre(n_point)

sum_ = 0

# Returns the value of the dimensionless integral as pi^4/15
for i in range(n_point):
    sum_ += weights[i] * integrand(roots[i])

# Approximate total power radiated
power = np.zeros(len(temp))
for i in range(len(temp)):
    print("Power radiated at T =", temp[i], ": ", np.format_float_scientific(constantReturner(temp[i]) * sum_, precision=3, exp_digits=2), "W/m^2",
          ", calculated Stefan's constant = ", np.format_float_scientific(constantReturner(temp[i]) * sum_ * (LIGHT_SPEED / 4) * (1 / (temp[i]**4)), precision=20, exp_digits=2), "W/m^2-K^4")
