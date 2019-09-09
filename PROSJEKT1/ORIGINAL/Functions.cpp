#include "Functions.h"
#include <iostream>
#include <cmath>

using namespace std;

void Thomas(double* d, double* a, double* b, double* g, double* u, int N){

    double *D, *G;

    D = new double[N];
    G = new double[N];

    D[0] = d[0];
    G[0] = g[0];

    // Forward substitution

    for (int i = 1; i<N; i++){
      D[i] = d[i]-(a[i-1]*b[i-1]) / D[i-1];
      G[i] = g[i] - (G[i-1]*b[i-1])/D[i-1];
    }

    // Backward sub.

    u[N-1] = G[N-1]/D[N-1];

    for (int i=N-2; i>=0; i--){
      u[i] = (G[i]-a[i]*u[i+1])/D[i];
    }

    //SPØR OM HJELP MED INDEKSERING!!!!

    delete[] D;
    delete[] G;

}


void SpecialThomas(double* q, double* u, int N){

    // Forward substitution

    for (int i = 1; i<N; i++){
      q[i] = q[i] + (q[i-1]*((double) i))/((double)(i+1));
    }

    // Backward sub.

    u[N-1] = ((double) N * q[N-1])/((double) (N + 1));
    //u[N-1] = (((double) (N))*q[N-1])/((double) (N+1));

    for (int i=N-2; i>=0; i--){
      u[i] = (((double)(i+1))*(q[i]+u[i+1]))/((double)(i+2));
    }


}


void Fill_q(double*q, int N, double h){
  double hh, x;
  hh = h*h;
  for (int i=0; i<N; i++){
    x = (double) (i+1)*h;
    q[i] = f(x)*hh;
  }
}


double f(double x){
  return 100*exp(-10*x);
}

double h_least(double x){
  double hh;

  hh = 24e-15/(10000*exp(-10*x));
  return pow(hh,0.25);
}

double exact(double x){
    return 1 - (1-exp(-10))*x - exp(-10*x);
  }
