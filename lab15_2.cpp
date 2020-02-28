#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

void randData(double *dPtr,int N,int M){
	double x;
	for(int i=0;i<49;i++){
		x=(rand()%101)/100.0;
		*dPtr=x;
		dPtr++;
	}
}

void findColSum(const double *dPtr,double *result,int N,int M){
	double sum=0;
	for(int i=0;i<49;i++){
		sum+=*dPtr;
		if((i+1)%7==0){
			*result=sum;
			result++;
			sum=0;
			dPtr-=41;
		}else{
			dPtr+=7;
		}
	}
}

void showData(double *show,int N,int M){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
		cout<<*show<<" ";
		show++;
		}
		cout<<endl;
	}
}
