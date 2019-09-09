import numpy as np
import matplotlib.pyplot as plt

import matplotlib
matplotlib.rc("xtick", labelsize=14)
matplotlib.rc("ytick", labelsize=14)
matplotlib.rcParams["mathtext.fontset"] = "stix"
matplotlib.rcParams["font.family"] = "STIXGeneral"

def u(x):
  return 1 - (1-np.exp(-10))*x - np.exp(-10*x)

def epsilon(h):
    hh = 1000*h / 3
    maskin = (4e-15/h**2 ) * u(0.23)
    return hh + maskin


h = np.linspace(0.0000000001, 0.1, 1000001)

plt.plot(np.log10(h), np.log10(epsilon(h)))
plt.axvline(x = -5.59, color = "k", ls = "--", label="log(h) = -5.59")
plt.title("Theoretical total error", size = 15)
plt.xlabel("log(h)", size = 15)
plt.ylabel("log($\epsilon$)", size = 15)
plt.legend()
plt.grid()
plt.show()
