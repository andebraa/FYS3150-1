import numpy as np
import matplotlib.pyplot as plt
import sys


M = int(sys.argv[1])
N = [int(10**i) for i in range(1,M+1)]

rel_e = np.zeros(M)
h = np.zeros(M)

for i in range(M):
    filename = "rel_error-n" + str(N[i]) + ".txt"
    load = np.loadtxt(filename)
    rel_e[i] = max(load)
    h[i] = 1/(N[i]+1.0)



plt.plot(np.log10(h),rel_e)
plt.xlabel("log(h)")
plt.ylabel("$\epsilon_r$")
plt.show()
