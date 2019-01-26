# Binary-Heap
minimum heap build up

#include<bits/stdc++.h>
using namespace std;

void minHeapify(int arr[], int i, int n){
	int left = 2*i+1;
	int right = 2*i+2;
	int smallest = i;
	if(left<n && arr[left]<arr[smallest]){
		smallest = left;
	}
	if(right<n && arr[right]<arr[smallest]){
		smallest = right;
	}
	if(smallest != i){
		swap(arr[i], arr[smallest]);
		minHeapify(arr,smallest,n);
	}
}

void convertMinHeap(int arr[], int n){
	for(int i=n/2-1; i>=0; i--){
		minHeapify(arr,i,n);
	}
}

void printArray(int *arr, int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}

int main()
{
	int n;
	int arr[1000];
	cout<<"enter the size of heap: ";
	cin>>n;
	cout<<"enter the min heap: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"min or ur entered heap array: ";
	printArray(arr,n);
	cout<<endl;
	convertMinHeap(arr,n);
	cout<<"max heap is: ";
	printArray(arr,n);
	cout<<endl;
}
