
#include <armadillo>
using namespace arma;
//using namespace std;

mat Rotate(mat , int& , int& , int );
mat Jacobi(mat , int, double &, vec);
double maxoffdiag(mat , int& , int&, double& );
bool TestEigen(mat,vec);
