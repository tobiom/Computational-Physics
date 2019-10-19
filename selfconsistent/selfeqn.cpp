#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#define _USE_MATH_DEFINES

#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a>b? b:a)
#define rep(i,n) for(int i=0;i<(int)(n);i++)

#define DIFF 0.00000001
#define GRVTY 9.80665

using namespace std;
using ll = long long;
using ld = long double;
using lint = long long int;

//equation: x=f(x)
inline ld func(ld x) {
    return expl(-x*x);
}

int main(void){
    // Steffensenの反復法
    ld dx;
    ld x[3]={};
    ld ep=0.0001;
    x[0] = 1.5;
    rep(i,1000) {
        cout << i << ":" << x[0] << endl;
        x[1] = func(x[0]);
        x[2] = func(x[1]);
        dx = powl(x[1]-x[0],2.0)/(x[0]-2.0*x[1]+x[2]);
        x[0] -= dx;
        if(abs(dx)<ep) {
            cout << "stop at i=" << i << endl;
            break;
        }
    }
    cout << x[0] << endl;
    return 0;
}