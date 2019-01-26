#include <bits/stdc++.h>
using namespace std;

struct activity{
	int start, finish;
};
bool activityCompare(activity s1, activity s2){
	return (s1.finish<s2.finish);
}

void maxActivity(activity arr[], int n){
	
	sort(arr, arr+n, activityCompare);
	cout<<"following activites are selected are: ";
	int i=0;
	cout<<"("<<arr[i].start<<","<<arr[i].finish<<"), ";
	for(int j=1;j<n;j++){
		if(arr[j].start>=arr[i].finish){
			cout<<"("<<arr[j].start<<", "<<arr[j].finish<<"), ";
			i=j;
		}
	}
}

int main()
{
	activity p[100];
    int n;
    cout<<"enter the element size: ";
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>p[i].start;
    	cin>>p[i].finish;
	}
	maxActivity(p,n); 
}
