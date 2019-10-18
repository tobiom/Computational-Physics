#include<cmath>
#include<fstream>
#include<iostream>
#define _USE_MATH_DEFINES

using namespace std;
using ld = long double;

const int N=64;
const ld dt=0.125;

inline ld func(ld t,ld p){
	return sqrt(t)/(exp(t-p)+1);
}
inline ld funcint(ld eta){
	ld t;
	ld x;
	ld dfx;
	ld res=0.0;
	for(int i=-N;i<=N;i++) {
		t = (ld)(i) * dt;
		x = exp(t-exp(-t));
		dfx = x * (1+exp(-t));
		res += func(x,eta) * dfx * dt ;
	}
	return res;
}
int main(){
	ld X,Y,wi,W;
	ld Dxi=0.01;
	ld Mxi=2.5;
	ofstream file("3D-Fermi-Chemical-Potential.dat");
	for(ld xi=-Mxi;xi<=Mxi;xi+=Dxi){
		W=Mxi*(exp(-xi)-1);
		//1.calc X=f(\xi)
		X = pow(funcint(W),-0.666666666666666666667);
		//2.calc Y=\xi X
		Y = W * X ;
		//3.plot (X,Y)
		file << X << " " << Y << endl;
	}
	return 0;
}