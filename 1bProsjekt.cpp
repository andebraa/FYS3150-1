#include <iostream>
#include <cmath>
#include <new>
#include <fstream>
#include <iomanip>


using namespace std;

//Declaration of functions
void Algorithm(double*, double*, double*, double*, double*, int);

double f(double);

void Fill_q(double*, int, double);


//Main function
int main(int argc, char* argv[]){

  int n = atoi(argv[1]);  //convert string to integer
  char* outfilename;
  outfilename = argv[2];

  double *a, *b, *c, *x, *q, h;

  a = new double[n];
  b = new double[n];
  c = new double[n];
  x = new double[n];
  q = new double[n];


  for (int i = 0; i<n; i++){
    a[i] = 2;
    b[i] = -1;
    c[i] = -1;
  }

  h = 1/((double) n + 1.0);

  Fill_q(q, n, h);

  Algorithm(a, b, c, x, q, n);

  //Nå er x laget - likningen er løst!

  //Skrive til fil for å plotte

    ofstream myfile;
    myfile.open(outfilename);
    for (int i = 0; i<n; i++){
      myfile << setprecision(9) << x[i] <<endl;
    }
    myfile.close();
  }


//Function specification
void Algorithm(double* a, double* b, double* c, double *x, double *q, int N){

  double *l, *d, *u, *y;

  // LU comp.
  l = new double[N];
  d = new double[N];
  u = new double[N];
  y = new double[N];

  d[0] = a[0];
  u[0] = c[0];


  for (int i = 0; i<N; i++){
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
