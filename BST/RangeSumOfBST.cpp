#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data = data;
    left = right = NULL;
  }
};
Node* Insert(Node* root,int val){
    if(root == NULL){
    root = new Node(val);
    return root;
    }
    if(val < root->data){
    root->left = Insert(root->left,val);
    }else{
    root->right = Insert(root->right,val);
    }
    return root;
}
Node* BuildBST(int *arr,int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
    root = Insert(root,arr[i]);
    }
    return root;
}
int SumInRange(Node* root,int start,int end){
  if(root == NULL){
    return 0;
  }
  if(start <= root->data && root->data <= end){
    return SumInRange(root->left,start,end) + SumInRange(root->right,start,end) + root->data;
  }else if(start > root->data){
    return SumInRange(root->right,start,end);
  }else{
    return SumInRange(root->left,start,end);
  }
}
int main(){
int arr[] = {8,5,3,1,4,6,10,11,14};
Node* root = BuildBST(arr,9);
cout<<"Sum in range = "<<SumInRange(root,5,12)<<endl;
return 0;
}