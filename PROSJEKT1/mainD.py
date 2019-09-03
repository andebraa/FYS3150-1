from os import system
import sys

print("Compiling executable")

system("c++ -O3 -c Functions.cpp")
system("c++ -O3 -o 1d.exe 1d.cpp Functions.o")
print("Finished compiling, executing....")

M = int(sys.argv[1])
N = [int(10**i) for i in range(1,M+1)]


for n in N:
    filename = "Least_H-n" + str(n) + ".txt"
    filename2 = "rel_error-n" + str(n) + ".txt"
    figurename = filename.strip(".txt") + ".png"
    system("./1d.exe" + " " + str(n) + " " + filename + " " + filename2)
    #system("python" + " " + "1dPlot.py" + " " + filename + " " +filename2)
    #system("mv" + " " + figurename + " " +  "~/Documents/FA/5_semester/FYS3150/GitHub/FYS3150/PROSJEKT1/Plots") #Lagrer plottene i en egen mappe
    #system("rm" + " " + filename) #Sletter txt-filene
    print("Finished with n = " + str(n) )

print("Done")
