# Graph-Algorithm

#include<iostream>
using namespace std;

#define CONNECTED 1;
#define DISCONNECTED 0;

int main()
{
	int node,edge,x,y;
	cout<<"enter the nodes number: ";
	cin>>node;
	int Graph[node+1][node+1];
	for(int i=1;i<=node;i++){
		for(int j=1;j<=node;j++){
			Graph[i][j]=DISCONNECTED
		}
	}
	cout<<"enter the edge number: ";
	cin>>edge;
	for(int i=1;i<=edge;i++){
		cout<<"enter the ede between x & y"<<endl;
		cin>>x>>y;
		Graph[x][y]=Graph[y][x] = CONNECTED;
	}
	cout<<"the adj matrix is: "<<endl;
	for(int i=1;i<=node;i++){
		for(int j=1;j<=node;j++){
			cout<<Graph[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
