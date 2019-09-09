from os import system
import sys

print("Compiling executable")

system("c++ -c Functions.cpp")
system("c++ -o 1c.exe 1c.cpp Functions.o")
print("Finished compiling, executing....")

M = int(sys.argv[1])
N = [10**i for i in range(1,M+1)]

#Takes one argument M in terminal
#Runs c++ file and writing the CPU times to a .txt-file


main_filename = "Ctimes.txt"
with open(main_filename, "w") as outfile:

    outfile.write("n" + " " + "timeused" + "\n")

    for n in N:
        filename = "time" + str(n) + ".txt"
        system("./1c.exe" + " " + str(n) + " " + filename) #Kjører programmet med de to argumentene som skal sendes inn
        with open(filename, "r") as infile:
            timeused = str(infile.readline())
            outfile.write(str(n) + " " + timeused)
        system("rm" + " " + "time" + str(n) + ".txt") #Sletter txt-filene
print("Done")
