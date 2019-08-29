import numpy as np
import matplotlib.pyplot as plt
import sys

filename = str(sys.argv[1])
figurename = filename.strip(".txt") + ".png"
v = np.loadtxt(filename)
n = len(v)

def u(x):
    return 1 - (1-np.exp(-10))*x - np.exp(-10*x)

x = np.linspace(0,1,n)

plt.plot(x,v, label="numerical solution, n = " + str(n))
plt.plot(x,u(x), label="analytical solution")
plt.legend()
plt.savefig(figurename)
plt.close()
