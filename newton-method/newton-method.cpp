#include<iostream>
#include<fstream>
#include<cmath>
#include"mpreal.h"
#define MAX(a,b) (((a) >= (b)) ? (a) : (b))

//using
using mpfr::mpreal;
using namespace std;

//constant numbers
const int digits = 48;
const mpreal one = mpreal(1.0,digits);
const mpreal two = mpreal(2.0,digits);
const mpreal zero = mpreal(0.0,digits);
const mpreal half = mpreal(0.5,digits);
const mpreal quater = mpreal(0.25,digits);
const mpreal gravity = mpreal(9.80665,digits);
const mpreal dt = one / mpreal(128.0,digits) ;

//equation : f(x)=0
mpreal func(mpreal x){return x*x-two;}

int main(void) {
    //set digits and precision
    cout.precision(digits);
    mpreal::set_default_prec(mpfr::digits2bits(digits));
    return 0;
}