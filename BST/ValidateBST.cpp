#include<iostream>
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
Node* BuildBST(int arr[],int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
    root = Insert(root,arr[i]);
    }
    return root;
}
bool ValidateHelper(Node* root,Node* min,Node* max){
    if(root == NULL){
    return true;
    }
    if(min != NULL && min->data > root->data){
    return false;
    }
    if(max != NULL && max->data < root->data){
    return false;
    }
    return ValidateHelper(root->left,min,root)
           && ValidateHelper(root->right,root,max);
}
bool Validate(Node* root){
    return ValidateHelper(root,NULL,NULL);
}
int main(){
int arr[] = {5,1,3,4,2,7};
Node* root = BuildBST(arr,6);
cout<<Validate(root)<<endl;
return 0;
}