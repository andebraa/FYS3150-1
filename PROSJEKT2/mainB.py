from os import system
import sys
import numpy as np

print("Compiling executable")

system("c++ -c Functions.cpp")
system("c++ -O3 -c 2b.cpp")
system("c++ -O3 -o 2b.exe 2b.o Functions.o -larmadillo")

#system("c++ -o 2b.exe 2b.cpp -larmadillo") #Functions.o")
print("Finished compiling, executing....")

#Runs the c++ file and plotting program
#Takes one argument M in terminal

M = int(sys.argv[1])

system("./2b.exe" + " " + str(M))
