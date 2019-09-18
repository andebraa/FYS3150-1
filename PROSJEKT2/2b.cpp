#include "Functions.h"
#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

void max_offdiag(mat, int*, int*, double*);

int main(){

  double n = 5;

  mat A = mat(n,n);
  A.fill(0.0);
  for (int i=0; i< n-1; i++){
    A(i,i) = 2;
    A(i,i+1) = -1;
    A(i+1,i) = -1;
  }
  A(n-1,n-1) = 2;

  A(4,3) = -8;
  A(2,4) = 7;

  int *k, *l;
  double * max_value;
  k = new int;
  l = new int;
  max_value = new double;

  max_offdiag(A, k, l, max_value);

  double eps = 1e-8;
  double max_iterat = n*n*n;
  int iterat = 0;

  while (max_value > eps && iterat < max_iterat){

  }

}

void max_offdiag(mat A, int *k, int *l, double *max_value){
  mat B = A;

  B.diag().zeros();

  uvec max_index;


  if (abs(B.max()) < abs(B.min()) ){
    *max_value = abs(B.min());
    max_index = ind2sub(size(B),B.index_min());

  }
  else{
    *max_value = abs(B.max());
    max_index = ind2sub(size(B),B.index_max());
  }

  *k = max_index[0];
  *l = max_index[1];
}
