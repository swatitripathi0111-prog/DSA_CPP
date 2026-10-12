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
Node* BuildBST(int *arr,int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
    root = Insert(root,arr[i]);
    }
    return root;
}
bool SearchInBST(Node* root,int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
      return SearchInBST(root->left,key);
    }else{
        return SearchInBST(root->right,key);
    }
}
int main(){
int arr[] = {5,1,3,4,2,7};
Node* root = BuildBST(arr,6);
cout<<SearchInBST(root,4)<<endl;
cout<<SearchInBST(root,10)<<endl;
return 0;
}