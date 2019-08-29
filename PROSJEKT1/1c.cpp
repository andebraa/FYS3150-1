#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Functions.h"
#include "time.h"
#include <cstdlib>

using namespace std;


//Main function
int main(int argc, char* argv[]){

  int n = atoi(argv[1]);  //convert string to integer
  char* outfilename;
  outfilename = argv[2];

  double *x, *q, h;
  time_t start, finish;

  x = new double[n];
  q = new double[n];

  h = 1/((double) n + 1.0);

  Fill_q(q, n, h);

  start = clock();
  SpecialThomas(q, x, n);

  finish = clock();

  double time_used = (double) (finish - start)/ (CLOCKS_PER_SEC);
  cout << "Time used for n = "<< n << ": " << time_used << " s" << endl;

  ofstream myfile;
  myfile.open(outfilename);
  myfile << time_used <<endl;
  myfile.close();

  }
