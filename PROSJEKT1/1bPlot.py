import numpy as np
import matplotlib.pyplot as plt
import sys
import matplotlib.animation as animation

#Settings for plots
import matplotlib
matplotlib.rc("xtick", labelsize=14)
matplotlib.rc("ytick", labelsize=14)
matplotlib.rcParams["mathtext.fontset"] = "stix"
matplotlib.rcParams["font.family"] = "STIXGeneral"


#Reads the .txt-files generated in the c++ file 1b.cpp
filename = str(sys.argv[1])
figurename = filename.strip(".txt") + ".png"
v = np.loadtxt(filename)

n = len(v)
h = 1/(float(n)+1)


def u(x):
    return 1 - (1-np.exp(-10))*x - np.exp(-10*x)

x = [float((i+1)*h) for i in range(n)]
x = np.array(x)


plt.plot(x,v, label="numerical solution, n = " + str(n))
plt.plot(x,u(x), label="analytical solution")
plt.grid()
plt.xlabel("x", size=30)
plt.title("Numerical vs. Analytical Solution", size = 20)
plt.ylabel("Function value", size=20)
plt.legend()
plt.savefig(figurename)
plt.close()
