#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>

#define MAX(a,b) (((a) >= (b)) ? (a) : (b))
#define DIFF 0.00000001
#define GRVTY 9.80665

using namespace std;
using ld = long double;

//equation : f(x)=0
inline ld func(ld x){
    return sinl(x)-1.0;
    //return x*x-1000.0;
    //return sin(x)-1.0;
    //return x*exp(x*x)-1.0;
}

int main(void) {
    int digit = 8;
    cout << fixed << setprecision(digit+4);
    ld x = 0.1;
    ld ep = powl(0.1,digit);
    ld dx = DIFF;
    int cnt = 0;
    do {
        x += dx;
        dx = -func(x)*dx/(func(x)-func(x-dx));
        cnt++;
    } while(abs(dx)>ep);
    cout << "f(x)=0" << endl << endl;
    cout << " 2x  =" << 2.0*x << endl;
    cout << " ep  =" << ep << endl;
    cout << "count:" << cnt << endl;
    return 0;
}