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
Node* insert(Node* root,int val){
   if(root == NULL){
    root = new Node(val);
    return root;
   }
   if(val < root->data){
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
Node* Helper(Node* root,int &sum) {
    if(root == NULL){
        return NULL;
    }
    Node* Right = Helper(root->right,sum);
    sum = sum + root->data;
    root->data = sum;
    Node* Left = Helper(root->left,sum);
    return root;
}
Node* bstToGst(Node* root) {
    int sum = 0;
    return Helper(root,sum);
}
void Inorder(Node* root){
 if(root == NULL){
    return;
 }
 Inorder(root->left);
 cout<<root->data<<" ";
 Inorder(root->right);
}
int main(){
int arr[] = {4,1,6,0,2,5,7,3,8};
int n = 9;
Node* root = BuildBST(arr,n);
bstToGst(root);
Inorder(root);
return 0;
}