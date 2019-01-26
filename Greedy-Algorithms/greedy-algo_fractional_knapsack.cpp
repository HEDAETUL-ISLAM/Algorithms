#include<bits/stdc++.h>
using namespace std;


struct item{
	int value,weight;
};

bool cmp(item x, item y){
	double a=(double)x.value/x.weight;
	double b=(double)y.value/y.weight;
	return a>b;
}

int fractionalKnapsack(int w, item arr[], int n){
	sort(arr, arr+n, cmp);
	int currentWeight=0;
	double finalValue=0.0;
	
	for(int i=0;i<n;i++){
		if(currentWeight + arr[i].weight<=w){
			currentWeight=currentWeight+arr[i].weight;
			finalValue=finalValue+arr[i].value;
		}
		else{
			int remain = w-currentWeight;
			finalValue=finalValue+arr[i].value*((double)remain / arr[i].weight);
			break;
		}
	}
	return finalValue;
}

int main()
{
	int w,n;
	cout<<"enter the weitht: ";
	cin>>w;
	cout<<"enter the size of ur entered data: ";
	cin>>n;
	item arr[100];
	cout<<"enter ur value first and then weight: ";
	for(int i=0;i<n;i++){
		cin>>arr[i].value;
		cin>>arr[i].weight;
	}
	cout<<"maximum value is: "<<fractionalKnapsack(w,arr,n)<<endl;
}
