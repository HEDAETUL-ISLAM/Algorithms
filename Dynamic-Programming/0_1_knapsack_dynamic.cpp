#include <bits/stdc++.h>
using namespace std;

struct item{
	int value, weight;
};
int max(int a, int b){
	return (a>b)?a:b ;
}

int knapsack(int w, item arr[], int n){
	int result[n+1][w+1];
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=w;j++){
			if(i==0 || j==0){
				result[i][j] = 0;
			}
			else if(arr[i-1].weight<=j){
				result[i][j]=max(arr[i-1].value + result[i-1][j-arr[i-1].weight], result[i-1][j]);
			}
			else{
				result[i][j]=result[i-1][j];
			}
		}
	}
	return result[n][w];
}

int main()
{
	int w,n;
	cout<<"enter the size of ur entered data: ";
	cin>>n;
	cout<<"enter the weitht: ";
	cin>>w;
	item arr[100];
	cout<<"enter ur value first and then weight: ";
	for(int i=0;i<n;i++){
		cin>>arr[i].value;
		cin>>arr[i].weight;
	}
	cout<<"max val is: "<<knapsack(w,arr,n);
}
