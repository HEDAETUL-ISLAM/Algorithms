#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int start, end, weight;
};
struct Graph{
	int V,E;
	struct Edge *edge;
};
struct Graph *createGraph(int V, int E){
	struct Graph *graph = new Graph;
	graph->V=V;
	graph->E=E;
	graph->edge = new Edge[E];
	return graph;
}
struct subset{
	int parent;
	int rank;
};
int find(struct subset subsets[], int i){
	if(subsets[i].parent != i){
		subsets[i].parent=find(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}
int Union(struct subset subsets[], int x, int y){
	int xroot=find(subsets,x);
	int yroot=find(subsets,y);
	
	if(subsets[xroot].rank < subsets[yroot].rank){
		subsets[xroot].parent=yroot;
	}
	else if(subsets[xroot].rank > subsets[yroot].rank){
		subsets[yroot].parent=xroot;
	}
	else{
		subsets[yroot].parent=xroot;
		subsets[xroot].rank++;
	}
}
int myComp(const void* a,const void* b){
	struct Edge *a1=(struct Edge*)a;
	struct Edge *b1=(struct Edge*)b;
	return a1->weight > b1->weight;
}
void kruskal(struct Graph *graph){
	int V=graph->V;
	struct Edge result [V];
	int e=0;
	int i=0;
	
	qsort(graph->edge,graph->E,sizeof(graph->edge[0]),myComp);
	
	struct subset *subsets = (struct subset*) malloc (V*sizeof(struct subset));
	for(int v=0;v<V;v++){
		subsets[v].parent=v;
		subsets[v].rank=0;
	}
	while(e<V-1){
		struct Edge next_edge=graph->edge[i++];
		int x = find(subsets,next_edge.start);
		int y = find(subsets,next_edge.end);
		if(x!=y){
			result[e++]=next_edge;
			Union(subsets,x,y);
		}
	}
	int sum=0;
	cout<<"constructed edges are: ";
	for(i=0;i<e;i++){
		cout<<result[i].start<<"---"<<result[i].end<<" = "<<result[i].weight<<endl;
		sum=sum+result[i].weight;
	}
	cout<<"total cost is: "<<sum;
}

int main()
{
	int V,E;
	cout<<"enter vertex size: ";
	cin>>V;
	cout<<"enter edge size: ";
	cin>>E;
	struct Graph *graph = createGraph(V,E);
	cout<<"enter start, end, weight sequentially: ";
	for(int i=0;i<E;i++){
		cin>>graph->edge[i].start;
		cin>>graph->edge[i].end;
		cin>>graph->edge[i].weight;
	}
	kruskal(graph);
	/* these for inputs
	0 1 10
	0 2 6
	0 3 5
	1 3 15
	2 3 4
	*/
}
