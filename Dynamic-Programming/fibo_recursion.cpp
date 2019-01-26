#include<iostream>
using namespace std;

int fibo(int size){
	if(size<=1){
		return size;
	}
	return fibo(size-1) + fibo(size-2);
}
int main()
{
	int size;
	cout<<"enter the size of ur fibo number: ";
	cin>>size;
	cout<<fibo(size)<<endl;
}
