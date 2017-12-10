#include<cmath>
#include<fstream>
#include<iostream>
#define _USE_MATH_DEFINES
using namespace std;
const int N=64;
const long double dt=0.125;
inline long double func(long double t,long double p){
	return sqrt(t)/(exp(t-p)+1);
}
inline long double funcint(long double eta){
	long double t;
	long double x;
	long double dfx;
	long double res=0.0;
	for(int i=-N;i<=N;i++) {
		t = (long double)(i) * dt;
		x = exp(t-exp(-t));
		dfx = x * (1+exp(-t));
		res += func(x,eta) * dfx * dt ;
	}
	return res;
}
int main(){
	long double X,Y,wi,W;
	long double Dxi=0.01;
	long double Mxi=2.5;
	ofstream file("data.dat");
	for(long double xi=-Mxi;xi<=Mxi;xi+=Dxi){
		W=Mxi*(exp(-xi)-1);
		//1.calc X=f(ƒÌ)
		X = pow(funcint(W),-0.666666666666666666667);
		//2.calc Y=ƒÌX
		Y = W * X ;
		//3.plot (X,Y)
		file << X << " " << Y << endl;
	}
	return 0;
}