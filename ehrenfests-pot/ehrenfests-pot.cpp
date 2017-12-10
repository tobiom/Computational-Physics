#include<iostream>
#include<fstream>
#include<cmath>
#include<random>
#define MAX(a,b) (((a) >= (b)) ? (a) : (b))
using namespace std;

int main(void) {
	int* flag;
	const int num=4000;
	const int T=100000;
	flag = new int[num];
	for(int i=0;i<num;i++) flag[i]=-1;
	//
	mt19937 xs(1);
	uniform_int_distribution<int> dist(0,num-1);
	//
	int sum=0;
	for(int i=0;i<T;i++) {
		flag[dist(xs)]*=-1;
		for(int i=0;i<num;i++) sum+=flag[i];
		cout << (double)sum/(double)num << endl;
		sum=0;
	}
	return 0;
}