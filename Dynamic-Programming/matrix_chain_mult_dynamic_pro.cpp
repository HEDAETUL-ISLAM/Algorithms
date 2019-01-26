#include<iostream>
using namespace std;

int mcm(int arr[], int n){
	int m[n][n];
	
	for(int i=1;i<n;i++){
		m[i][i]=0;
	}
	for(int L=2;L<n;L++){
		for(int i=1;i<n-L+1;i++){
			int j=i+L-1;
			m[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++){
				int q=m[i][k]+m[k+1][j]+arr[i-1]*arr[k]*arr[j];
				if(q<m[i][j]){
					m[i][j]=q;
				}
			}
		}
	}
	return m[1][n-1];
}

int main()
{
	int n, arr[100];
	cout<<" enter size: ";
	cin>>n;
	cout<<" enter size of matrixes common number: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<" your result is: "<<mcm(arr,n);
}
