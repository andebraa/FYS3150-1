#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Functions.h"
#include <cstdlib>

using namespace std;

ofstream myfile, myfile2;

int main(int argc, char* argv[]){

  int n = atoi(argv[1]);  //convert string to integer
  char* outfilename, *outfilename2;
  outfilename = argv[2];
  outfilename2 = argv[3];

  double *u, *q, *H, *rel_e, h, small_h, *a, *b, *d;


  u = new double[n];
  q = new double[n];
  H = new double[n];
  rel_e = new double[n];

  a = new double[n];
  b = new double[n];
  d = new double[n];


  for (int i = 0; i<n; i++){
    d[i] = 2;
    a[i] = -1;
    b[i] = -1;
  }
  h = 1/((double) n + 1.0);

  Fill_q(q, n, h);


  Thomas(d, a, b, q, u, n);

  double x;
  for (int i = 0; i < n; i++){
    H[i] = h_least(u[i]);
    x = (double) (i+1)*h;
    rel_e[i] = log10(abs((u[i] - exact(x))/exact(x)));
    }


  myfile.open(outfilename);
  myfile2.open(outfilename2);

  for (int i = 0; i<n; i++){
    myfile << setprecision(9) << H[i] <<endl;
    myfile2 << setprecision(9) << rel_e[i] <<endl;
  }
  myfile.close();
  myfile2.close();

  delete[] H;
  delete[] q;
  delete[] rel_e;

}
