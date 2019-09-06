import numpy as np
import matplotlib.pyplot as plt
import sys

filename = str(sys.argv[1])
figurename = filename.strip(".txt") + ".png"
v = np.loadtxt(filename)

n = len(v)
h = 1/(float(n)+1)


def u(x):
    return 1 - (1-np.exp(-10))*x - np.exp(-10*x)

x = [float((i+1)*h) for i in range(n)]
x = np.array(x)



print(x)
print(x1)

plt.plot(x,v, label="numerical solution, n = " + str(n))
plt.plot(x,u(x), label="analytical solution")
plt.xlabel("x")
plt.legend()
plt.savefig(figurename)
plt.close()
