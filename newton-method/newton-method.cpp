#include<iostream>
#include<fstream>
#include<cmath>
#include"mpreal.h"
#define MAX(a,b) (((a) >= (b)) ? (a) : (b))
#define DIFF "0.00000001"
#define GRVTY "9.80665"

//using
using mpfr::mpreal;
using namespace std;

//constant numbers
const int digits = 60;

//equation : f(x)=0
inline mpreal func(mpreal x){
    return x*tanh(x)-"1.0";
    //return x*x-"1000.0";
    //return sin(x)-"1.0";
    //return x*exp(x*x)-"1.0";
}

int main(void) {
    cout.precision(digits);
    mpreal::set_default_prec(mpfr::digits2bits(digits));
    mpreal x = "2.0";
    mpreal ep = "0.0000000000000000000000000000000000000000000000000000001";
    mpreal dx = DIFF;
    int cnt = 0;
    do {
        x += dx;
        dx = -func(x)*dx/(func(x)-func(x-dx));
        cnt++;
    } while(abs(dx)>ep);
    cout << "f(x)=x*tanh(x)-1=0" << endl << endl;
    cout << "digit:" << digits << endl;
    cout << "  x  =" << x << endl;
    cout << " ep  =" << ep << endl;
    cout << "count:" << cnt << endl;
    return 0;
}