from os import system
import sys

"""

print("Compiling executable")

system("c++ -c Functions.cpp")
system("c++ -o 1b.exe 1b.cpp Functions.o")
print("Finished compiling, executing....")
N = [10, 100, 1000]
for n in N:
    system("./1b.exe" + " " + str(n) + " " + "1b-n" + str(n) + ".txt") #Kjører programmet med de to argumentene som skal sendes inn
    system("python" + " " + "1bPlot.py" + " " + "1b-n" + str(n) + ".txt") #Kjører plotprogrammet
    system("mv" + " " + "1b-n" + str(n) + ".png" + " " + "~/Documents/FA/5_semester/FYS3150/GitHub/FYS3150/PROSJEKT1/PlotsLU") #Lagrer plottene i en egen mappe
    system("rm" + " " + "1b-n" + str(n) + ".txt") #Sletter txt-filene
print("Done")
"""



print("Compiling executable")

system("c++ -c Functions.cpp")
system("c++ -o 1b.exe 1b.cpp Functions.o")
print("Finished compiling, executing....")


M = int(sys.argv[1])
N = [10**i for i in range(1,M+1)]
for n in N:
    filename = "1b-n" + str(n) + ".txt"
    filename2 = "time" + str(n) + ".txt"
    figurename = filename.strip(".txt") + ".png"
    system("./1b.exe" + " " + str(n) + " " + filename + " " + filename2)
    system("python" + " " + "1bPlot.py" + " " + filename) #Kjører plotprogrammet
    system("mv" + " " + figurename + " " + "~/Documents/FA/5_semester/FYS3150/GitHub/FYS3150/PROSJEKT1/Plots") #Lagrer plottene i en egen mappe
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
