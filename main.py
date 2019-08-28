from os import system

print("Compiling executable")
system("c++ -c -O3 1bProsjekt.cpp")
system("c++ -o 1bProsjekt.exe 1bProsjekt.o")
print("Finished compiling, executing....")
N = [10, 100, 1000]
for n in N:
    system("./1bProsjekt.exe" + " " + str(n) + " " + "1b-n" + str(n) + ".txt") #Kjører programmet med de to argumentene som skal sendes inn
    system("python" + " " + "1bPlot.py" + " " + "1b-n" + str(n) + ".txt") #Kjører plotprogrammet
    system("mv" + " " + "1b-n" + str(n) + ".png" + " " + "~/Documents/FA/5_semester/FYS3150/Prosjekt_1/plots") #Lagrer plottene i en egen mappe
    system("rm" + " " + "1b-n" + str(n) + ".txt") #Sletter txt-filene
print("Done")
