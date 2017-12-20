#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<random>
using namespace std;
#define MIN(a,b) (((a) <= (b)) ? (a) : (b))

inline void Ehrenfest(int num, int times) {
	//
	bool* flag;
	flag = new bool[num];
	for(long i=0;i<num;i++) flag[i]=false;
	//
	random_device seed_gen;
	mt19937 xs(seed_gen());
	uniform_int_distribution<int> dist(0,num-1);
	//
	ofstream ofs("ehrenfests-pot-num=" + to_string(num) + ".dat");
	//
	int cur;
	int sum=-num;
	for(int i=0;i<times;i++) {
		//ofs << setprecision(9) << i << " " << logl(absl((long double)sum/(long double)num)) << endl;
		ofs << setprecision(9) << i << " " << (long double)sum/(long double)num << endl;
		cur = dist(xs);
		flag[cur] = !flag[cur];
		//sum += ((((int)(flag[cur])<<1)-1)<<1);
		sum += (flag[cur]*2-1)*2 ;
	}
	ofs.close();
	return;
}

inline void Ehrenfest(int num, int times, ofstream &zero) {
	//
	bool z_point=1;
	bool* flag;
	flag = new bool[num];
	for(long i=0;i<num;i++) flag[i]=false;
	//
	random_device seed_gen;
	mt19937 xs(seed_gen());
	uniform_int_distribution<int> dist(0,num-1);
	//
	ofstream ofs("ehrenfests-pot-num=" + to_string(num) + ".dat");
	//ofstream ofs_log("ehrenfests-log-num=" + to_string(num) + ".dat");
	//
	int cur;
	int sum=-num;
	for(int i=0;i<times;i++) {
		ofs << setprecision(9) << i << " " << (long double)sum/(long double)num << endl;
		//ofs_log << setprecision(9) << i << " " << -logl(-(long double)sum) << endl;
		if(sum==0&&z_point==1) {
			zero << num << " " << i << endl;
			z_point = 0;
		}
		cur = dist(xs);
		flag[cur] = !flag[cur];
		sum += (flag[cur]*2-1)*2 ;
		if(sum>0) break;
	}
	ofs.close();
	//ofs_log.close();
	return;
}

inline void EhrenfestList(int max,int min) {
	ofstream zero("zeropoint-data-from-" + to_string(max) + "-to-" + to_string(min) + ".dat");
	for(int i=max;i>=min;i-=1000) Ehrenfest(i,i*3,zero);
	return;
}

int main(void) {
	/*
	int N;	cout << "num =? : " ; cin >> N;
	int T;	cout << "Time=? : " ; cin >> T;
	Ehrenfest(N,T);
	*/
	//
	int maxN;	cout << "N_max/1000 =? : " ; cin >> maxN;
	int minN;	cout << "N_min/1000 =? : " ; cin >> minN;
	EhrenfestList(maxN*1000,minN*1000);
	//
	return 0;
}