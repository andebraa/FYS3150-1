#include "Functions.h"
#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;


double max_offdiag(mat A, int &k, int &l){
  //Locates the maximum off-diagonal element and the indices.
  //Returns the max. value
  mat B = A;

  B.diag().zeros();

  double max_value;
  uvec max_index;


  if (abs(B.max()) < abs(B.min()) ){
    max_value = abs(B.min());
    max_index = ind2sub(size(B),B.index_min());

  }
  else{
    max_value = abs(B.max());
    max_index = ind2sub(size(B),B.index_max());
  }

  k = max_index[0];
  l = max_index[1];

  return max_value;
}


mat rotation(mat A, int k, int l, int n){


  mat S = mat(n,n);
  S.eye();
  double t, tau, s, c;

  //Bestemmer sin og cos
  if (A(k,l) != 0){
  tau = (A(l,l) - A(k,k))/(2.0*A(k,l));
  if (tau >= 0){
    t = tau + sqrt(1.0 + tau*tau);
  }
  else{
    t = - (tau + sqrt(1.0 + tau*tau));
  }
  c = 1.0/sqrt(1+t*t);
  s = t*c;
}
  else{
    c = 1.0;
    s = 0;
  }

  S(k,k) = c;
  S(l,l) = c;
  S(k,l) = -s;
  S(l,k) = s;

  return S;
}
