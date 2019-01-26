#include<iostream>
using namespace std;

#define unvisited -1
#define marked 0
#define visited 1
#define CONNECTED 1
#define DISCONNECTED 0
#define SIZE 100

int graph[SIZE+1][SIZE+1],label[SIZE+1];
int queue[SIZE],head,tail;
int node, edge;

void initialQueue(){
	head=tail=0;
}
void enqueue(int node){
	queue[tail++]=node;
}
int dequeue(){
	return queue[head++];
}
bool queueEmpty(){
	return head==tail;
}

void BFS(int source, int node){
	for(int i=1;i<=node;i++){
		label[i]=unvisited;
	}
	enqueue(source);
	label[source]=marked;
	
	while(!queueEmpty()){
		int visitedNode=dequeue();
		cout<<visitedNode<<" ";
		for(int i=1;i<=node;i++){
			if(graph[visitedNode][i] == CONNECTED){
				if(label[i] == unvisited){
					label[i]=marked;
					enqueue(i);
				}
			}
		}
		label[visitedNode]=visited;
	}
	cout<<endl;
}

int main()
{
	int x,y,source;
	cout<<"enter the nodes number: ";
	int node;
	cin>>node;
	for(int i=1;i<=node;i++){
		for(int j=1;j<=node;j++){
			graph[i][j]=DISCONNECTED;
		}
	}
	cout<<"enter teh edge number: ";
	int edge;
	cin>>edge;
	for(int i=1;i<=edge;i++){
		cout<<"enter the ede between x & y"<<endl;
		cin>>x>>y;
		graph[x][y]=graph[y][x]=CONNECTED;
	}
	initialQueue();
	cout<<"give a source: ";
	cin>>source;
	BFS(source,node);
}







