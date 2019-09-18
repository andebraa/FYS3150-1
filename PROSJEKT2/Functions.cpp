#include "Functions.h"
#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;


void rotation(double ** A, double ** R, int k, int l, int n){
  //Her er indekseringen basert på at jeg lager en matrise med for-loop

  double t, tau, s, c;

  //Bestemmer sin og cos
  if (A[k][l] != 0){
  tau = A[l][l] - A[k][k]/(2*A[k][l]);
  if (tau > 0){
    t = - tau + sqrt(1 + tau*tau) ;
  }
  else{
    t = - tau - sqrt(1 + tau*tau);
  }
  c = 1.0/sqrt(1+t*t);
  s = t*c;
}
  else{
    c = 1.0;
    s = 0;

    double a_kk, a_ll, a_ik, a_il, r_ik, r_il;
    //Endrer verdien til den største ikke-diag element
    a_kk = A[k][k];
    a_ll = A[l][l];
    A[k][k] = a_kk*c*c - 2*A[k][l]*c*s + a_ll*s*s;
    A[l][l] = a_ll*c*c + 2*A[k][l]*c*s + a_kk*s*s;

    A[k][l] = 0;
    A[l][k] = 0;
    //Endrer de resterende elementene
    for (int i = 0; i < n; i++){
      if (i != l && i != k){
        a_ik = A[i][k];
        a_il = A[i][l];
        A[i][k] = a_ik*c - a_il*s;
        A[k][i] = A[i][k];
        A[i][l] = a_il*c + a_ik*s;
        A[l][i] = A[i][l];
      }
      r_ik = R[i][k];
      r_il = R[i][k];
      R[i][k] = c*r_ik - s*r_il;
      R[i][l] = c*r_il + s*ik;
    }

}
