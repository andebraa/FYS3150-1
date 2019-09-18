#include "Functions.h"
#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;


int main(int argc, char* argv[]){
  int n = atoi(argv[1]);

//Filling matrix A
  mat A = mat(n,n);
  double h = 1/((double) n);
  double hh = h*h;

  A.fill(0.0);
  for (int i=0; i< n-1; i++){
    A(i,i) = 2/hh;
    A(i,i+1) = -1/hh;
    A(i+1,i) = -1/hh;
  }
  A(n-1,n-1) = 2/hh;

//Finding maximum off-diagonal element and its indicies
  int k, l;
  double max_value;

  max_value = max_offdiag(A, k, l);

  double eps = 1e-8;
  int max_iterat = 1e6;
  int iterat = 0;
  mat S, initial_eigenvec;
  vec computed_eigval, initial_eigenvalues;

  computed_eigval = vec(n);
  initial_eigenvalues = vec(n);

  eig_sym(initial_eigenvalues, initial_eigenvec, A);


  while (max_value*max_value > eps && iterat < max_iterat){
    max_value = max_offdiag(A, k, l);
    S = rotation(A, k, l, n);
    A = trans(S)*A*S;

    if (EigenvalueTest(A, initial_eigenvalues) != true){
      cout<<"Eigenvalues not preserved"<<endl;
      break;
    }
    iterat = 1 + iterat;
  }

  cout<<"Everything okay yo!!!"<<endl;
  cout<<"Number of iterations"<<" "<<iterat<<endl;
  return 0;

}
