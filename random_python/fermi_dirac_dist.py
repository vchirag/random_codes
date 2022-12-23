# To plot Fermi-Dirac distribution
# f(E) as a function of (E-E_F) at temperatures 0, 100, 300
# Take Boltzmann constant in eV

import numpy as np
import matplotlib.pyplot as plt


def fermiDirac(temp, energy, fermiEnergy=0, BOLTZMANN_CONSTANT=8.617e-5):
    factor = 1 + np.exp((energy - fermiEnergy) / (BOLTZMANN_CONSTANT * temp))
    return (1 / factor)


dist = [[], [], []]
energy = []
for i in np.arange(-1, 1, 0.001):
    dist[0].append(fermiDirac(0, i))
    dist[1].append(fermiDirac(100, i))
    dist[2].append(fermiDirac(300, i))
    energy.append(i)

fig, ax = plt.subplots()

fig.set_figheight(4)
fig.set_figwidth(15)

ax.set_xlabel("$E - E_f$", fontsize=16)
ax.set_ylabel("$f(E)$", fontsize=16)
ax.xaxis.grid()
ax.yaxis.grid()

ax.set_xticks(np.arange(-1, 1, 0.1))
ax.set_xlim(-1., 1.)

ax.set_title("Fermi-Dirac distibution for $E_f = 0$", fontsize=16)

ax.plot(energy, dist[0], label="T = 0K")
ax.plot(energy, dist[1], label="T = 100K")
ax.plot(energy, dist[2], label="R = 300K")
ax.legend(loc="upper right", fontsize=12)
