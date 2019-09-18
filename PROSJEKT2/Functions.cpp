#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <armadillo>
#include "Functions.h"

using namespace std;
using namespace arma;


mat Rotate(mat A, int &k, int &l, int n){
  // Indeksering basert på armadillo [rad, kolonne]
  double t, tau, s, c;

  mat S = mat(n,n);
  S.eye();

  if (A(k,l) != 0){

    tau = (A(l,l)-A(k,k))/(2*A(k,l));
    if (tau >= 0){
      t = tau + sqrt(1.0+tau*tau);
    }else{
      t= -tau - sqrt(1.0+tau*tau);
    }

    c = 1.0/sqrt(1+t*t);
    s = c*t;

  }else{
    c = 1.0;
    s = 0.0;
  }

  S(k,k) = c;
  S(l,l) = c;
  S(k,l) = -s;
  S(l,k) = s;

  return S;
}


mat Jacobi(mat A, int n, double &max_value){

  mat R = mat(n,n);
  R.fill(0.0);
  for (int i=0; i< n-1; i++){
    R(i,i)= 1;
  }
  R(n-1,n-1)= 1;


  //double &max_offdiag;
  //max_offdiag= new double;

  int k,l;
  double epsilon = 1e-8;
  double max_it = (double) n * (double) n * (double) n;
  int it = 0;

  mat S;

  max_value = maxoffdiag(A,k,l,max_value);

  while (max_value*max_value > epsilon && (double) it < max_it){
    max_value = maxoffdiag(A,k,l,max_value);
    S = Rotate(A, k, l, n);
    A = trans(S)*A*S;
    it++;
  }


  cout << "Number of iterations" <<" "<< it << endl;

  A.print();
  return A;

}


//Max av off-diagonalelementer
double maxoffdiag(mat A, int &k, int &l, double &max_value){

  mat B = A;
  B.diag().zeros();

  max_value=0;

  uvec max_index;

  if (abs(B.max()) < abs(B.min()) ){

    max_value = abs(B.min());
    max_index = ind2sub(size(B),B.index_min());

  }else{

    max_value = abs(B.max());
    max_index = ind2sub(size(B),B.index_max());
  }


  k = max_index[0];
  l = max_index[1];

  return max_value;
  //cout<<*k<<endl;
  //cout<<*l<<endl;

}


//Sjekke ortogonaliteten til egenvektorer i den nye matrisen (skal også være symmetrisk)
//Sjekke at egenverdiene er bevart (Armadillo,
//finn egenverdiene ved starten og deretter for hver iterasjon sjekke at
//de nye egenverdiene er like de gamle)
