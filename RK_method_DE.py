# To use: R-K method to solve the given differential equations
# u_1' = 3u_1 + 2u_2 - (2t^2 + 1)e^(2t), u_1(0) = 1
# u_2' = 4u_1 + u_2 + (t^2 + 2t - 4)e^(2t), u_2(0) = 1; 0 <= t  <=1, h = 0.2

import numpy as np


def f1(t, u1, u2):
    factor_1 = 3 * u1 + 2 * u2
    factor_2 = (2 * t**2 + 1) * np.exp(2 * t)

    return factor_1 - factor_2


def f2(t, u1, u2):
    factor_1 = 4 * u1 + u2
    factor_2 = (t**2 + 2 * t - 4) * np.exp(2 * t)

    return factor_1 + factor_2


def k(t, u1, u2, flag):
    if flag == 1:
        return h * f1(t, u1, u2)

    elif flag == 2:
        return h * f2(t, u1, u2)


t_0 = 0
h = 0.1
t_max = 1

# The initial conditions at t = 0
u1 = 1
u2 = 1

# Number of intervals
n = (t_max - t_0) / h

for i in range(int(n)):
    t = t_0 + i * h

    k1 = h * f1(t, u1, u2)
    k2 = h * f2(t, u1, u2)

    s1 = h * f1(t + h / 2, u1 + k1 / 2, u2 + k2 / 2)
    s2 = h * f2(t + h / 2, u1 + k1 / 2, u2 + k2 / 2)

    l1 = h * f1(t + h / 2, u1 + s1 / 2, u2 + s2 / 2)
    l2 = h * f2(t + h / 2, u1 + s1 / 2, u2 + s2 / 2)

    p1 = h * f1(t + h, u1 + l1, u2 + l2)
    p2 = h * f2(t + h, u1 + l1, u2 + l2)

    u1 += (1 / 6) * (k1 + 2 * s1 + 2 * l1 + p1)
    u2 += (1 / 6) * (k2 + 2 * s2 + 2 * l2 + p2)

    print("Value of u1 after", i + 1, "th iteration = ", u1)
    print("Value of u2 after", i + 1, "th iteration = ", u2)
    print("")
