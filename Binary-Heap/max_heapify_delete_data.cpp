__>>max_heapify_delete_data


#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int i, int n){
	int left = 2*i+1;
	int right = 2*i+2;
	int largest = i;
	if(left<n && arr[left]>arr[largest]){
		largest = left;
	}
	if(right<n && arr[right]>arr[largest]){
		largest = right;
	}
	if(largest != i){
		swap(arr[i], arr[largest]);
		maxHeapify(arr,largest,n);
	}
}

void convertMaxHeap(int arr[], int n){
	for(int i=n/2-1; i>=0; i--){
		maxHeapify(arr,i,n);
	}
}

void printArray(int *arr, int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}
void deleteItem(int arr[],int &n,int num){
	for(int i=0;i<n;i++){
		if(num == arr[i]){
			arr[i] = INT_MAX;
		}
	}
	convertMaxHeap(arr,n);
	swap(arr[0],arr[n-1]);
	n--;
	convertMaxHeap(arr,n);
	printArray(arr,n);
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
	cout<<"ur entered heap array: ";
	printArray(arr,n);
	cout<<endl;
	convertMaxHeap(arr,n);
	cout<<"max heap is: ";
	printArray(arr,n);
	cout<<endl;
	int num;
	cin>>num;
	deleteItem(arr,n,num);
	cout<<endl<<n;
}
