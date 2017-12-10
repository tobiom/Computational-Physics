#include<stdio.h>
#include<math.h>
#include"mtwister.h"

#define dT 0.5
#define NPANEL 5
#define SAMPS 10000
#define TEMPS 10000
#define SPNUM (NPANEL*NPANEL)

int p0,p1,dE;
double T=0.5;
double En,M,ChiT_N,E_N,CT2_N2;
double J=1.0;
int spins[NPANEL][NPANEL]={};
int Index[NPANEL][NPANEL][4]={};
double SqMag[TEMPS][2]={};
double UnitE[TEMPS][2]={};

double drnd(){
  return genrand_real2();
}

int updown(double x){
  if(x<=0.5) return 1;
  return -1;
}

void SetIndex(){
  int i,j;
  for(i=0;i<NPANEL;i++) for(j=0;j<NPANEL;j++) {
      Index[i][j][0]=(i+1)%NPANEL;
      Index[i][j][1]=(i+NPANEL-1)%NPANEL;
      Index[i][j][2]=(j+1)%NPANEL;
      Index[i][j][3]=(j+NPANEL-1)%NPANEL;
  }
  return;
}

void Calc_dE(){
  dE=2*spins[p0][p1]
    *(spins[Index[p0][p1][0]][p1]
        +spins[Index[p0][p1][1]][p1]
         +spins[p0][Index[p0][p1][2]]
          +spins[p0][Index[p0][p1][3]]);
  return;
}

void Rev(){
  p0=drnd()*NPANEL;
  p1=drnd()*NPANEL;
  Calc_dE();
  if(drnd()<exp(-(double)(dE)/T)) spins[p0][p1]*=-1;
  return;
}

double Energy(int i,int j){
  return -J*(double)(spins[i][j]*(spins[Index[i][j][0]][j]+spins[i][Index[i][j][2]]));
}

void ProcessB(int temp){
  int i,j,k,l;
  for(i=NPANEL*NPANEL;0<i;--i) for(j=10000;0<j;--j) Rev();
  for(k=SAMPS;0<k;--k) {
    for(i=NPANEL-1;0<=i;--i) for(j=NPANEL-1;0<=j;--j) {
      En=Energy(i,j);
      UnitE[temp][0]+=En;
      UnitE[temp][1]+=En*En;
      SqMag[temp][0]+=(double)(spins[i][j]);
      SqMag[temp][1]+=(double)(spins[i][j]*spins[i][j]);
    }
    for(l=NPANEL*NPANEL*100;0<l;--l) Rev();
  }
  SqMag[temp][0]/=(double)(SAMPS);
  SqMag[temp][1]/=(double)(SAMPS);
  UnitE[temp][0]/=(double)(SAMPS);
  UnitE[temp][1]/=(double)(SAMPS);
  return;
}

int main(){

  int i,j,k;

  //SetWin();

  SetIndex();

  init_genrand(2552);

  for(i=0;i<NPANEL;i++) for(j=0;j<NPANEL;j++) spins[i][j]=updown(drnd());

  //main

  printf("T m ChiT/N E/N CTT/NN\n");

  for(k=TEMPS;0<k;--k){

    ProcessB(TEMPS-k);

    //if(k%1000==0) MCS();

    //Rev();

    //usleep(1000);

    M=SqMag[TEMPS-k][0];

    ChiT_N=SqMag[TEMPS-k][1]-M*M;

    E_N=UnitE[TEMPS-k][0];

    CT2_N2=UnitE[TEMPS-k][1]-E_N*E_N;

    printf("%f %f %f %f %f\n",T,M,ChiT_N,E_N,CT2_N2);

    T+=dT;

  }


  return 0;

}
