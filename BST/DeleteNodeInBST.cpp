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
Node* GetIS(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
Node* DelNode(Node* root,int val){
if(root == NULL){
    return NULL;
}
if(val < root->data){
    root->left = DelNode(root->left,val);
}else if(val > root->data){
    root->right = DelNode(root->right,val);
}else{
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }
    if(root->left == NULL || root->right == NULL){
    return root->left == NULL ? root->right : root->left;
    }
    Node* IS = GetIS(root->right);
    root->data = IS->data;
    root->right = DelNode(root->right,IS->data);
    return root;
}
 return root;
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
int arr[] = {5,1,3,4,2,7};
Node* root = BuildBST(arr,6);
DelNode(root,5);
Inorder(root);
return 0;
}