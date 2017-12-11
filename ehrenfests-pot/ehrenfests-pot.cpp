#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<random>
using namespace std;
#define MIN(a,b) (((a) <= (b)) ? (a) : (b))

int main(void) {
	int num=25;
	int T=2000;
	bool* flag;
	//
	cout << "num =? : " ; cin >> num;
	cout << "Time=? : " ; cin >> T;
	//
	flag = new bool[num];
	for(long i=0;i<num;i++) flag[i]=false;
	ofstream ofs("ehrenfests-pot-num=" + to_string(num) + ".dat");
	//
	mt19937 xs(1);
	uniform_int_distribution<int> dist(0,num-1);
	//
	int cur;
	int sum=-num;
	for(int i=0;i<T;i++) {
		ofs << setprecision(9) << i  << " " << (long double)sum/(long double)num << endl;
		cur = dist(xs);
		flag[cur] = !flag[cur];
		sum += ((((int)(flag[cur])<<1)-1)<<1);
	}
	ofs.close();
	return 0;
}