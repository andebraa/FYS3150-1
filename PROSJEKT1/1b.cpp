#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Functions.h"

using namespace std;


//Main function
int main(int argc, char* argv[]){

  int n = atoi(argv[1]);  //convert string to integer
  char* outfilename;
  outfilename = argv[2];

  double *a, *b, *c, *x, *q, h;

  a = new double[n];
  b = new double[n];
  c = new double[n];
  x = new double[n];
  q = new double[n];


  for (int i = 0; i<n; i++){
    a[i] = 2;
    b[i] = -1;
    c[i] = -1;
  }

  h = 1/((double) n + 1.0);

  Fill_q(q, n, h);

  //Thomas(a, b, q, x, n);

  ThomasLU(a, b, c, x, q, n);



  //Skrive til fil for å plotte

    ofstream myfile;
    myfile.open(outfilename);
    for (int i = 0; i<n; i++){
      myfile << setprecision(9) << x[i] <<endl;
    }
    myfile.close();

  }
