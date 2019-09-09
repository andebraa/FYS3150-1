from os import system
import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

#Settings for plots
import matplotlib
matplotlib.rc("xtick", labelsize=14)
matplotlib.rc("ytick", labelsize=14)
matplotlib.rcParams["mathtext.fontset"] = "stix"
matplotlib.rcParams["font.family"] = "STIXGeneral"

print("Compiling executable")

system("c++ -O3 -c Functions.cpp")
system("c++ -O3 -o 1e.exe 1e.cpp Functions.o -larmadillo")
print("Finished compiling, executing....")

M = int(sys.argv[1])
N = [int(10**i) for i in range(1,M+1)]

#Takes one argument M in terminal
#Runs the c++ file 

for n in N:
    filename = "1e-n" + str(n) + ".txt"
    filename2 = "LUtime-" + str(n) + ".txt"
    figurename = filename.strip(".txt") + ".pdf"
    system("./1e.exe" + " " + str(n) + " " + filename + " " + filename2)
    system("python" + " " + "1bPlot.py" + " " + filename)
    system("mv" + " " + figurename + " " + "~/Documents/5.semester/COMPFYS/FYS3150/FYS3150/PROSJEKT1/Plots") #Lagrer plottene i en egen mappe
    system("rm" + " " + filename) #Sletter txt-filene
    print("Finished with n = " + str(n) )

#For-loop construct a .txt-file for CPU-times for different N

main_filename = "LUtimes.txt"
with open(main_filename, "w") as outfile:

    outfile.write("n" + " " + "timeused" + "\n")

    for n in N:
        filename3 = "LUtime-" + str(n) + ".txt"
        with open(filename3, "r") as infile:
            timeused = str(infile.readline())
            outfile.write(str(n) + " " + timeused)
        system("rm" + " " + filename3) #Sletter txt-filene




print("Done")
