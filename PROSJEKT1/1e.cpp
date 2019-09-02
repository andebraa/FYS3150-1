#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Functions.h"
#include "time.h"
#include <cstdlib>
#include <armadillo>

using namespace std;
using namespace arma;

int main(int argc, char* argv[]){

  int n = atoi(argv[1]);  //convert string to integer
  char* outfilename;
  outfilename = argv[2];
  time_t start, finish;

  mat A = mat(n,n);
  A.fill(0.0);
  for (int i=0; i< n-1; i++){
    A(i,i) = 2;
    A(i,i+1) = -1;
    A(i+1,i) = -1;
  }
  A(n-1,n-1) = 2;

  mat L, U;

  double h, *q, *y, *x;
  q = new double[n];
  y = new double[n];
  x = new double[n];

  h = 1/((double) n + 1.0);

  Fill_q(q, n, h);

  start = clock();

  //LU decomp.
  lu(L,U,A);

  //Forward sub.

  y = solve(L,q);
  x = solve(U, y);

  finish = clock();

  double time_used = (double) (finish - start)/ (CLOCKS_PER_SEC);
  cout << "Time used for n = "<< n << ": " << time_used << " s" << endl;

  ofstream myfile;
  myfile.open(outfilename);
  myfile << time_used <<endl;
  myfile.close();

}
