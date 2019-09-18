import os
import sys

n = int(sys.argv[1])

print("Compiling...")
os.system("c++ -O3 -c 1a.cpp Functions.cpp")
print("Executing...")
os.system("c++ -O3 -o 1a.exe 1a.o Functions.o -larmadillo")
os.system("./1a.exe" + " " + str(n))
