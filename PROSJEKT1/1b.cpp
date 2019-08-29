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



  double *a, *b, *c, *x, *q, h;
  time_t start, finish;

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
  /* Kan fylle disse enklere ved armadillo - trenger terminalkommando-hjelp! */

  h = 1/((double) n + 1.0);

  Fill_q(q, n, h);


  start = clock();

  Thomas(a, b, q, x, n);

  //ThomasLU(a, b, c, x, q, n);

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
