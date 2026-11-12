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
Node* BSTfromSortedVec(vector<int> &arr,int st,int end){
if(st > end){
    return NULL;
}
int mid = (st+end)/2;
Node* Curr = new Node(arr[mid]);
Curr->left = BSTfromSortedVec(arr,st,mid-1);
Curr->right = BSTfromSortedVec(arr,mid+1,end);
return Curr;
}
void GetInorder(vector<int> &nodes,Node* root){
  if(root == NULL){
    return;
   }
   GetInorder(nodes,root->left);
   nodes.push_back(root->data);
   GetInorder(nodes,root->right);
}
Node* BalanceBST(Node* root){
    vector<int> nodes;
    GetInorder(nodes,root);
    return BSTfromSortedVec(nodes,0,nodes.size()-1);
}
void Preorder(Node* root){
 if(root == NULL){
    return;
 }
 cout<<root->data<<" ";
 Preorder(root->left);
 Preorder(root->right);
}
int main(){
Node* root = new Node(6);
root->left = new Node(5);
root->left->left = new Node(4);
root->left->left->left = new Node(3);

root->right = new Node(7);
root->right->right = new Node(8);
root->right->right->right = new Node(9);
root = BalanceBST(root);
Preorder(root);
return 0; 
}