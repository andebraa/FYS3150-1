import numpy as np
import matplotlib.pyplot as plt
import sys

filename = str(sys.argv[1])
filename2 = str(sys.argv[2])
figurename = filename.strip(".txt") + ".png"
figurename2 = filename2.strip(".txt") + ".png"
h_minste = np.loadtxt(filename)

rel_e = np.loadtxt(filename2)

n = len(h_minste)

def u(x):
    return 1 - (1-np.exp(-10))*x - np.exp(-10*x)

x = np.linspace(0,1,n+1)



plt.plot(x[0:-1],h_minste, label="Minste steglegnde")
plt.xlabel("x")
plt.ylabel("h")
plt.legend()
plt.savefig(figurename)
plt.close()

"""
plt.plot(np.log10(h_minste), rel_e)
plt.xlabel("Stepsize")
plt.ylabel("Relative error")
plt.savefig(figurename2)
plt.close()
"""
