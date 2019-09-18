#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Functions.h"
#include "time.h"

using namespace std;
ofstream myfile, myfile2;

//Main function
int main(int argc, char* argv[]){

  int n = atoi(argv[1]);  //convert string to integer
  char* outfilename, *outfilename2;
  outfilename = argv[2];
  outfilename2 = argv[3];


  double *d, *a, *b, *x, *q, h;
  time_t start, finish;

  d = new double[n];
  a = new double[n];
  b = new double[n];
  x = new double[n];
  q = new double[n];


  for (int i = 0; i<n; i++){
    d[i] = 2;
    a[i] = -1;
    b[i] = -1;
  }

  h = 1/((double) n + 1.0);


  Fill_q(q, n, h);


  start = clock();

  Thomas(d, a, b, q, x, n);


  finish = clock();

  double time_used = (double) (finish - start)/ (CLOCKS_PER_SEC);
  cout << "Time used for n = "<< n << ": " << time_used << " s" << endl;


  myfile.open(outfilename);
  for (int i = 0; i<n; i++){
    myfile << setprecision(9) << x[i] <<endl;
  }
  myfile.close();


  myfile2.open(outfilename2);
  myfile2 << time_used <<endl;
  myfile2.close();

  }
