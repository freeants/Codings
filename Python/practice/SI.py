import scipy.integrate as spi
import numpy as np
import matplotlib.pyplot as plt

# N is total population
N = 10000
# β is infection coefficiency
beta = 0.25
# recovery coe
gamma = 0
# Initial Infections
I_0 = 1
# Starting can be infected
S_0 = N - I_0
# Epidemic time
T = 150

INI = (S_0, I_0)


def funcSI(inivalue, _):
    Y = np.zeros(2)
    X = inivalue
    Y[0] = -(beta*X[0]*X[1])/N+gamma*X[1]
    Y[1] = (beta*X[0]*X[1])/N-gamma*X[1]
    return Y


T_range = np.arange(0, T+1)
RES = spi.odeint(funcSI, INI, T_range)

plt.plot(RES[:, 0], color='darkblue', label='Susceptible', marker='.')
plt.plot(RES[:, 1], color='red', label='Infection', marker='.')
plt.title('SI Model')
plt.legend()
plt.xlabel('Day')
plt.ylabel('Number')
plt.show()
