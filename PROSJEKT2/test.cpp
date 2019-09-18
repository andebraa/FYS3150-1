#include <iostream>
#include <cmath>
#include <fstream>
#include "Functions.h"
#include <iomanip>
#include <cstdlib>
#include <armadillo>

using namespace std;
using namespace arma;


int main(){

  double *k,*l;

  mat A = mat(5,5);
  A.fill(0.0);
  for (int i=0; i< 4; i++){
    A(i,i) = 2;
    A(i,i+1) = -1;
    A(i+1,i) = -1;
  }
  A(4,4) = 2;
  A(4,3) = -8;

  double max = maxoffdiag(A);



  cout<<"max verdi"<<max<<endl;

}
