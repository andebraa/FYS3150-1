#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Functions.h"
#include <cstdlib>

using namespace std;

ofstream myfile;

int main(int argc, char* argv[]){

  int n = atoi(argv[1]);  //convert string to integer
  char* outfilename;
  outfilename = argv[2];

  double *u, *q, *rel_e, h, small_h, *a, *b, *d, *x;


  u = new double[n];
  q = new double[n];
  rel_e = new double[n];

  a = new double[n];
  b = new double[n];
  d = new double[n];

  x = new double[n];

  for (int i = 0; i<n; i++){
    d[i] = 2;
    a[i] = -1;
    b[i] = -1;
  }
  h = 1/((double) n + 1.0);

  Fill_q(q, n, h);


  SpecialThomas(q, x, n);


  double y;
  for (int i = 0; i < n; i++){
    y = (double) (i+1)*h;
    rel_e[i] = log10(abs((x[i] - exact(y))/exact(y)));
    }


  myfile.open(outfilename);
  for (int i = 0; i<n; i++){
    myfile << setprecision(9) << rel_e[i] <<endl;
  }
  //myfile.close();
  myfile.close();

  delete[] q;
  delete[] rel_e;
  delete[] x;
  delete[] u;

}
