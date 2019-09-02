from os import system
import sys

print("Compiling executable")

system("c++ -O3 -c Functions.cpp")
system("c++ -O3 -o 1e.exe 1e.cpp Functions.o -larmadillo")
print("Finished compiling, executing....")

M = int(sys.argv[1])
N = [int(10**i) for i in range(1,M+1)]

for n in N:
    filename = "LUtime-" + str(n) + ".txt"
    system("./1e.exe" + " " + str(n) + " " + filename)
    print("Finished with n = " + str(n) )


main_filename = "LUtimes.txt"
with open(main_filename, "w") as outfile:

    outfile.write("n" + " " + "timeused" + "\n")

    for n in N:
        filename2 = "LUtime-" + str(n) + ".txt"
        with open(filename2, "r") as infile:
            timeused = str(infile.readline())
            outfile.write(str(n) + " " + timeused)
        system("rm" + " " + filename2) #Sletter txt-filene




print("Done")
