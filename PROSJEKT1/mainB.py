from os import system
import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import seaborn as sns
plt.style.use("bmh")
sns.color_palette("hls",1)

import matplotlib
matplotlib.rc("xtick", labelsize=14)
matplotlib.rc("ytick", labelsize=14)
matplotlib.rcParams["mathtext.fontset"] = "stix"
matplotlib.rcParams["font.family"] = "STIXGeneral"

print("Compiling executable")

system("c++ -c Functions.cpp")
system("c++ -o 1b.exe 1b.cpp Functions.o")
print("Finished compiling, executing....")


M = int(sys.argv[1])
N = [10**i for i in range(1,M+1)]
for n in N:
    filename = "1b-n" + str(n) + ".txt"
    filename2 = "time" + str(n) + ".txt"
    figurename = filename.strip(".txt") + ".pdf"
    system("./1b.exe" + " " + str(n) + " " + filename + " " + filename2)
    system("python" + " " + "1bPlot.py" + " " + filename) #Kjører plotprogrammet
    system("mv" + " " + figurename + " " + "~/Documents/5.semester/COMPFYS/FYS3150/FYS3150/PROSJEKT1/Plots") #Lagrer plottene i en egen mappe
    system("rm" + " " + filename) #Sletter txt-filene
print("Done")


NN = [10**i for i in range(1,M+1)]

main_filename = "Btimes.txt"
with open(main_filename, "w") as outfile:

    outfile.write("n" + " " + "timeused" + "\n")

    for n in NN:
        filename2 = "time" + str(n) + ".txt"
        with open(filename2, "r") as infile:
            timeused = str(infile.readline())
            outfile.write(str(n) + " " + timeused)
        system("rm" + " " + "time" + str(n) + ".txt") #Sletter txt-filene
