# Plot radial probability density for H atom upto n = 3

import numpy as np
import matplotlib.pyplot as plt

a_0 = 1


def rad_nl(r, n, l):
    factor_1 = np.exp(-r / (n * a_0))
    factor_2 = a_0**(-3 / 2)

    if n == 1 and l == 0:
        return 2 * factor_1 * factor_2

    if n == 2:
        if l == 0:
            factor_3 = 1 - (r / (2 * a_0))
            return np.sqrt(1 / 2) * factor_1 * factor_2 * factor_3

        if l == 1:
            factor_3 = r / a_0
            return np.sqrt(1 / 24) * factor_1 * factor_2 * factor_3
    if n == 3:
        if l == 0:
            factor_3 = 1 - (2 / 3) * (r / a_0) + (2 / 27) * (r**2 / a_0**2)
            return np.sqrt(4 / 27) * factor_1 * factor_2 * factor_3

        if l == 1:
            factor_3 = (1 - (1 / 6) * (r / a_0)) * (r / a_0)
            return (8 / 27) * np.sqrt(1 / 6) * factor_1 * factor_2 * factor_3

        if l == 2:
            factor_3 = (r / a_0)**2
            return (4 / 81) * np.sqrt(1 / 30) * factor_1 * factor_2 * factor_3


radial_distribution = [[], [[], []], [[], [], []]]
distance = []

for i in np.arange(0, 30 * a_0, 0.01):
    distance.append(i)
    radial_distribution[0].append(i**2 * np.abs(rad_nl(i, 1, 0))**2)
    radial_distribution[1][0].append(i**2 * np.abs(rad_nl(i, 2, 0))**2)
    radial_distribution[1][1].append(i**2 * np.abs(rad_nl(i, 2, 1))**2)
    radial_distribution[2][0].append(i**2 * np.abs(rad_nl(i, 3, 0))**2)
    radial_distribution[2][1].append(i**2 * np.abs(rad_nl(i, 3, 1))**2)
    radial_distribution[2][2].append(i**2 * np.abs(rad_nl(i, 3, 2))**2)

fig, ax = plt.subplots()

fig.set_figheight(4)
fig.set_figwidth(15)

ax.set_xlabel("$r/a_0$", fontsize=16)
ax.set_ylabel("Radial Probability", fontsize=16)
ax.xaxis.grid()
ax.yaxis.grid()
ax.set_xticks(np.arange(0, 30 * a_0, 1))
ax.set_xlim(0, 30 * a_0)

ax.set_title("Radial Probability Density", fontsize=16)
ax.plot(distance, radial_distribution[0], label="1s")
ax.plot(distance, radial_distribution[1][0], label="2s")
ax.plot(distance, radial_distribution[1][1], label="2p")
ax.plot(distance, radial_distribution[2][0], label="3s")
ax.plot(distance, radial_distribution[2][1], label="3p")
ax.plot(distance, radial_distribution[2][2], label="3d")
ax.legend(loc="upper right", fontsize=12)
