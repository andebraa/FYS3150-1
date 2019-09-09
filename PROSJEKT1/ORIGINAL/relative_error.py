import numpy as np
import matplotlib.pyplot as plt
import sys

import matplotlib
matplotlib.rc("xtick", labelsize=14)
matplotlib.rc("ytick", labelsize=14)
matplotlib.rcParams["mathtext.fontset"] = "stix"
matplotlib.rcParams["font.family"] = "STIXGeneral"

M = int(sys.argv[1])
N = [int(10**i) for i in range(1,M+1)]

rel_e = np.zeros(M)
h = np.zeros(M)
index_max = np.zeros(M)

for i in range(M):
    filename = "rel_error-n" + str(N[i]) + ".txt"
    load = np.loadtxt(filename)
    rel_e[i] = max(load)
    index_max[i] = np.argmax(load)
    h[i] = 1/(float(N[i])+1.0)



plt.plot(np.log10(h),rel_e)
plt.xlabel("log(h)", size = 15)
plt.axvline(x = -5.59, color = "k", ls = "--", label="log(h) = -5.59")
plt.ylabel("$\epsilon_r$", size = 20)
plt.title("Relative error", size = 15)
plt.legend()
plt.grid()
plt.show()
