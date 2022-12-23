# Given: Maxwell's velocity distribution function:
# N(v)dv = 4piv^2(m/2pikt)^1.5 exp(-mv^2/2kt)dv
# To find v_rms and v_mean @ T = 300K for N_2 gas: m = 4.65E-26

import math
import scipy.special
from scipy import special

TEMP = 400
BOLTZMANN_CONSTANT = 1.380649E-23
MASS = 4.65E-26


def constantRETURNER():
    factor1 = [2 * math.sqrt(2 * BOLTZMANN_CONSTANT * TEMP),
               4 * BOLTZMANN_CONSTANT * TEMP]
    factor2 = [math.sqrt(math.pi * MASS), MASS * math.sqrt(math.pi)]
    return (factor1[0] / factor2[0], factor1[1] / factor2[1])


def integrandRMS(x):
    return math.sqrt(x**3)


def integrandMean(x):
    return x


def gaussLaguerre(n_point):
    roots, weights = scipy.special.roots_laguerre(n_point, mu=False)
    return roots, weights


const_mean = constantRETURNER()[0]
const_RMS = constantRETURNER()[1]

n_point = int(input("Enter the order of Gaussian-Laguerre quadrature: "))
roots, weights = gaussLaguerre(n_point)

sum_mean = 0
sum_RMS = 0
for i in range(n_point):
    sum_mean += weights[i] * integrandMean(roots[i])
    sum_RMS += weights[i] * integrandRMS(roots[i])

print("RMS speed from integration = ", math.sqrt(const_RMS * sum_RMS),
      "m/s, RMS speed from analytical expression", math.sqrt(3 * BOLTZMANN_CONSTANT * TEMP / MASS), "m/s")
print("Mean speed from integration = ", const_mean * sum_mean, "m/s, RMS speed from analytical expression",
      math.sqrt(8 * BOLTZMANN_CONSTANT * TEMP / (MASS * math.pi)), "m/s")
