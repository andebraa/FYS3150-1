#include "Functions.h"
#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;


int main(int argc, char* argv[]){
  int n = atoi(argv[1]);

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

  int k, l;
  double max_value;

  max_value = max_offdiag(A, k, l);


  double eps = 1e-8;
  int max_iterat = 1e6;
  int iterat = 0;

  mat S;

  while (max_value*max_value > eps && iterat < max_iterat){
    max_value = max_offdiag(A, k, l);
    S = rotation(A, k, l, n);
    A = trans(S)*A*S;
    iterat = 1 + iterat;
  }

  cout<<"Number of iterations"<<" "<<iterat<<endl;

  vec computed_eigval = vec(n);
  computed_eigval = A.diag();
  computed_eigval = sort(computed_eigval, "ascend");
  computed_eigval.print("Computed eigenvalues:");
  return 0;

}
