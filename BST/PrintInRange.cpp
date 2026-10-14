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
void PrintInRange(Node* root,int start,int end){
   if(root == NULL){
     return;
   }
   if(start <= root->data && root->data <= end){
    cout<<root->data<<" ";
    PrintInRange(root->left,start,end);
    PrintInRange(root->right,start,end);
   }else if(start > root->data){
     PrintInRange(root->right,start,end);
   }else{
    PrintInRange(root->left,start,end);
   }
}
int main(){
int arr[] = {8,5,3,1,4,6,10,11,14};
Node* root = BuildBST(arr,9);
PrintInRange(root,5,12);
return 0;
}