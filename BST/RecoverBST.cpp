#include<iostream>
using namespace std;
class Node{
public: 
   int val;
   Node* left;
   Node* right;
   Node(int data){
    this->val = data;
    left = right = NULL;
   }
};
Node* insert(Node* root,int val){
   if(root == NULL){
    root = new Node(val);
    return root;
   }
   if(val < root->val){
    root->left = insert(root->left,val);
   }else{
    root->right = insert(root->right,val);
   }
   return root;
} 
Node* BuildBST(int arr[],int n){
   Node* root = NULL;
   for(int i=0;i<n;i++){
    root = insert(root,arr[i]);
   }
   return root;
}
Node* previous = NULL;
Node* first = NULL;
Node* second = NULL;
void inorder(Node* root){
if(root == NULL){
return;
}
inorder(root->left);
if(previous != NULL && previous->val > root->val){
    if(first == NULL){
    first = previous;
    }
    second = root;
}
previous = root;
inorder(root->right);
}
void recoverTree(Node* root) {
inorder(root);
swap(first->val,second->val);      
}
void PrintInorder(Node* root){
if(root == NULL){
 return;
}
PrintInorder(root->left);
cout<<root->val<<" ";
PrintInorder(root->right);
}
int main(){
int arr[] = {3,1,4,2};
Node* root = BuildBST(arr,4);
PrintInorder(root);
return 0;
}