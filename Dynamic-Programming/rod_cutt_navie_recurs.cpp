#include<iostream>
using namespace std;

int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

int cutRod(int price[], int n){
	if(n<=0){
		return 0;
	}
	int max_val=INT_MIN;
	for(int i=0;i<n;i++){
		max_val=max(max_val,price[i]+cutRod(price,n-i-1));
	}
	return max_val;
}

int main()
{
	int size,price[100];
	cout<<"enter the size: ";
	cin>>size;
	cout<<"enter number of price: ";
	for(int i=0;i<size;i++){
		cin>>price[i];
	}
	cout<<"maximum obtaind value is: "<<cutRod(price,size);
}
