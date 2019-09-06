from os import system
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
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

for i in range(M):
    filename = "rel_error-n" + str(N[i]) + ".txt"
    load = np.loadtxt(filename)
    rel_e[i] = max(load)
    h[i] = 1/(N[i]+1.0)
    #system("rm" + " " + filename)

print("The maximimum value of relative error for each value of N:", rel_e)

plt.plot(np.log10(h),rel_e)
plt.grid()
plt.xlabel("log(h)",size =20)
plt.ylabel("$\epsilon_r$", size=30)
plt.title("Relative error", size=25)
plt.savefig("Relativfeil.pdf")
plt.show()
