#include "Functions.h"

#include <cmath>

using namespace std;

void ThomasLU(double* a, double* b, double* c, double *x, double *q, int N){

  double *l, *d, *u, *y;

  // LU decomp.
  l = new double[N];
  d = new double[N];
  u = new double[N];
  y = new double[N];

  d[0] = a[0];
  u[0] = c[0];


  for (int i = 1; i<N; i++){
    l[i] = b[i]/d[i-1];
    d[i] = a[i] - l[i]*u[i-1];
    u[i] = c[i];
  }

  // Forward substitution

  y[0] = q[0];

  for (int i = 1; i<N; i++){
    y[i] = q[i]-l[i]*y[i-1];
  }

  // Backward sub.

  x[N-1] = y[N-1]/d[N-1];
  for (int i=N-2; i>0; i--){
    x[i] = (y[i]-u[i]*x[i+1])/d[i];
  }

  delete[] l;
  delete[] d;
  delete[] u;
  delete[] y;

}

void Thomas(double* d, double* l, double* g, double* u, int N){

    double *D, *G;

    D = new double[N];
    G = new double[N];

    D[0] = d[0];

    // Forward substitution

    for (int i = 1; i<N; i++){
      D[i] = d[i]-pow((l[i-1]),2) / D[i-1];
      G[i] = g[i] - (G[i-1]*l[i-1])/D[i-1];

    }

    // Backward sub.

    u[N-1] = G[N-1]/D[N-1];

    for (int i=N-2; i>0; i--){
      u[i] = (G[i]-l[i]*u[i+1])/D[i];
    }

    delete[] D;
    delete[] G;

}


void SpecialThomas(double* g, double* u, int N){

    double *G;

    G = new double[N];


    // Forward substitution

    for (int i = 1; i<N; i++){
      G[i] = g[i] + (G[i-1]*(i-1))/i;
    }

    // Backward sub.

    u[N-1] = ((N-1)*g[N-1])/N;

    for (int i=N-2; i>0; i--){
      u[i] = (i*(G[i]+u[i+1]))/(i+1);
    }

    delete[] G;

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
