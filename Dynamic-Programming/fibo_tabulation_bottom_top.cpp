#include<iostream>
using namespace std;

int fibo(int size){
	int arr[size+1];
	arr[0]=0;
	arr[1]=1;
	for(int i=2;i<=size;i++){
		arr[i]=arr[i-1]+arr[i-2];
	}
	return arr[size];
}

int main()
{
	int size;
	cout<<"enter the size: ";
	cin>>size;
	cout<<fibo(size)<<endl;
}
