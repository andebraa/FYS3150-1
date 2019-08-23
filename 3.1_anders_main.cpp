#include <iostream>
#include <cmath>
#include <new>

using namespace std;

float f(float x){
    x = atan(x);
    return x;
}

float f_deriv(float x, float h){
    float h_inv = (1/h);
    float deriv = (f(x+h) - f(x))*h_inv;

    return deriv;
}

float f_deriv_alt(float x, float h)
{
    float h_inv = (1/(2*h));
    float deriv = (f(x+h) - f(x-h))*h_inv;
    return deriv;
}

int main()
{
    int stepnum = 10; //number of elements in stepsize
    float x = sqrt(2);
    double * stepsize;
    stepsize = new*double[stepnum];




    for ( float h=10; h>-100; h-- ){
        printf(" %g : %g", h, f_deriv( x,  h));
    }

}

//hei på deg
