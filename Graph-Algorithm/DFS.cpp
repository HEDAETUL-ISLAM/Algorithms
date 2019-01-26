#include<iostream>
using namespace std;
int EDGE[10][10],i,j,k,node,stack[10],top,start,visit[10],visited[10];
int edge;
int main()
{
    cout <<"enter the node no:";
    cin >> node;
    cout <<"enter the edge no:";
    cin >> edge;
    cout <<"enter edge between i to j"<<endl;
    for(k=1; k<=edge; k++)
    {
        cin >>i>>j;
        EDGE[i][j]=1;
    }
    cout <<"enter the starting node:";
    cin >>start;
    cout <<"result:";
    cout << start <<" ";
    visited[start]=1;
    k=1;
    while(k<node)
    {
        for(j=node; j>=1; j--)
            if(EDGE[start][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                stack[top]=j;
                top++;
            }
        start=stack[--top];
        cout<<start << " ";
        k++;
        visit[start]=0;
        visited[start]=1;
    }
}
