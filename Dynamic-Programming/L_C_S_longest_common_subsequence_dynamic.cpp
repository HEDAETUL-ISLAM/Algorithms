#include<bits/stdc++.h>
using namespace std;

int lcs(char *X, char *Y, int m, int n){
	int L[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0){
				L[i][j]=0;
			}
			else if(X[i-1] == Y[j-1]){
				L[i][j]=L[i-1][j-1]+1;
			}
			else{
				L[i][j]=max(L[i-1][j],L[i][j-1]);
			}
		}
	}
	return L[m][n];
}
int max(int a, int b){
	return (a>b)?a:b;
}

int main()
{
	char X[100],Y[100];
	
	cout<<"enter first string: ";
	cin>>X;
	cout<<"enter second string: ";
	cin>>Y;
	int m=strlen(X);
	int n=strlen(Y);
	cout<<"longest common sunsequence is: "<<lcs(X,Y,m,n)<<endl;
}
