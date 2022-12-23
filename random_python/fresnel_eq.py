# Fresnel Equations
# Given: n2=  2.42, n1= 1

import numpy as np
import matplotlib.pyplot as plt

n1 = 1
n2 = 2.42

beta = n2 / n1


def alpha(theta):
    factor_1 = 1 - ((n1 / n2) * np.sin(theta))**2
    return (np.sqrt(factor_1) / np.cos(theta))


def transmittance(theta):
    factor_1 = 4 * alpha(theta) * beta
    factor_2 = (alpha(theta) + beta)**2
    return factor_1 / factor_2


def reflectance(theta):
    factor_1 = alpha(theta) - beta
    factor_2 = alpha(theta) + beta
    return (factor_1 / factor_2)**2


brewster = 0
crossover = 0

trans = []
reflec = []
angle = []

for i in np.arange(0, np.pi / 2, 0.001):
    if round(alpha(i), 2) == beta:
        brewster = i

    if round(reflectance(i), 2) == round(transmittance(i), 2):
        crossover = i

    trans.append(transmittance(i))
    reflec.append(reflectance(i))
    angle.append((180 / np.pi) * i)


print("The Brewster angle for the given configuration is:",
      round((180 / np.pi) * brewster, 2), "degrees")
print("The crossover angle for the given configuration is:",
      round((180 / np.pi) * crossover, 2), "degrees")

fig, ax = plt.subplots()

fig.set_figheight(4)
fig.set_figwidth(15)

ax.set_xlabel("$\\theta_i$", fontsize=16)
ax.set_ylabel("R or T", fontsize=16)
ax.xaxis.grid()
ax.yaxis.grid()
ax.set_xticks(np.arange(0, 90, 5))
ax.set_xlim(0, 90)

ax.plot(angle, trans, label="R")
ax.plot(angle, reflec, label="T")
ax.axvline((180 / np.pi) * crossover, color="k")
ax.axvline((180 / np.pi) * brewster, color="k")
ax.legend(loc="upper right", fontsize=12)

plt.show()
