#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Functions.h"
#include <cstdlib>
#include <armadillo>

using namespace std;
using namespace arma;



int main(int argc,char* argv[]){

  int n = atoi(argv[1]);

  mat A = mat(n,n);
  A.fill(0.0);
  double h = 1/((double) n);
  double hh = h*h;
  for (int i=0; i< n-1; i++){
    A(i,i) = 2/hh;
    A(i,i+1) = -1/hh;
    A(i+1,i) = -1/hh;
  }
  A(n-1,n-1) = 2/hh;
  //A(n-1,n-2) = -20;

  vec InitialEigenval;
  mat InitialEigenvec;
  eig_sym(InitialEigenval, InitialEigenvec, A);

  int k;
  int l;

  double max_value;

  A = Jacobi(A,n, max_value, InitialEigenval);

  /*
  A = Jacobi(A,n, max_value);


  vec com_eigen = vec(n);
  com_eigen = A.diag();
  com_eigen = sort(com_eigen,"ascend");
  com_eigen.print("Computed eigenvalues:");
  */
}
