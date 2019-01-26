#include<iostream>
using namespace std;

#define NIL -1
#define MAX 100

int lookup[MAX];

void initial(){
	for(int i=0;i<MAX;i++){
		lookup[i]=NIL;
	}
}

int fibo(int size){
	if(lookup[size] == NIL){
		if(size<=1){
			lookup[size]=size;
		}
		else{
			lookup[size]=fibo(size-1)+fibo(size-2);
		}
	}
	return lookup[size];
}

int main()
{
	int size;
	cout<<"enter the size: ";
	cin>>size;
	initial();
	cout<<fibo(size)<<endl;
}
