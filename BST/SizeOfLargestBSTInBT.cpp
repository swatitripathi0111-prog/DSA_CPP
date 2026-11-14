#include<iostream>
#include<vector>
#include<climits>
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
class Info{
public:
  bool isBST;
  int min;
  int max;
  int sz;
  Info(bool isBST,int min,int max,int sz){
    this->isBST = isBST;
    this->min = min;
    this->max = max;
    this->sz = sz;
  }
};
static int MaxSize;
Info* LargestBST(Node* root){
  if(root == NULL){
  return new Info(true,INT_MAX,INT_MIN,0);
  }
  Info* LeftInfo = LargestBST(root->left);
  Info* RightInfo = LargestBST(root->right);
  int CurrMin = min(root->data,min(LeftInfo->min,RightInfo->min));
  int CurrMax = max(root->data,max(LeftInfo->max,RightInfo->max));
  int Currsize = LeftInfo->sz + RightInfo->sz + 1;
  if(LeftInfo->isBST && RightInfo->isBST && root->data > LeftInfo->max && root->data < RightInfo->min){
    MaxSize = max(MaxSize,Currsize);
    return new Info(true,CurrMin,CurrMax,Currsize);
  }
  return new Info(false,CurrMin,CurrMax,Currsize);
}
int main(){
Node* root = new Node(50);
root->left = new Node(30);
root->left->left = new Node(5);
root->left->right = new Node(20);

root->right = new Node(60);
root->right->left = new Node(45);
root->right->right = new Node(70);
root->right->right->left = new Node(65);
root->right->right->right = new Node(80);
LargestBST(root);
cout<<"Max Size = "<<MaxSize<<endl;
return 0;
}