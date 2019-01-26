__>>max_heapify_linked_list

#include<iostream>
using namespace std;

struct maxHeapify{
	int data;
	maxHeapify *left;
	maxHeapify *right;
};

maxHeapify *creatNewNode(int data){
	maxHeapify *newNode = new maxHeapify();
	newNode->data = data;
	newNode->left = newNode->right =NULL;
	return newNode;
}

int count = 0;

maxHeapify *insert(maxHeapify *root, int data){
	
	maxHeapify *n  = creatNewNode(data);
	if(root == NULL){
		root = n;
	}
	else if(data > root->data){
		maxHeapify *temp = root;
		root = n;
		root->left=temp;
	}
	else{
		if(count%2==0)
			root->left = insert(root->left,data);
		else
			root->right = insert(root->right,data);
		count++;
	}
	return root;
}

void maxHeap(maxHeapify *root){
	if(root != NULL){
		cout<<root->data<<" ";
		maxHeap(root->left);
		maxHeap(root->right);
	}
}
int main()
{
	maxHeapify *root = NULL;
	int n,data,number;
	cout<<"enter the elements number: ";
	cin>>n;
	cout<<"enter the elements: ";
	for(int i=0;i<n;i++){
		cin>>data;
		root=insert(root,data);
	}
	cout<<"max heap is: ";
	maxHeap(root);
}
