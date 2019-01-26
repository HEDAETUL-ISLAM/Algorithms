#include<iostream>
using namespace std;

void maxActivity(int *s, int *f, int n){
	cout<<"following activites are selected n: ";
	int i=0;
	cout<<i<<" ";
	for(int j=1;j<n;j++){
		if(s[j]>=f[i]){
			cout<<j<<" ";
			i=j;
		}
	}
}

int main()
{
	int n;
	int s[100],f[100];
	cout<<"enter the size of ur array: ";
	cin>>n;
	cout<<"enter 1st array: ";
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	cout<<"enter 2nd array: ";
	for(int j=0;j<n;j++){
		cin>>f[j];
	}
	maxActivity(s,f,n);
}
