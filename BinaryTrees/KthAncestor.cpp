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
static int idx = -1;
Node* BuildTree(vector<int> nodes){
idx++;
if(nodes[idx] == -1){
    return NULL;
}
Node* CurrNode = new Node(nodes[idx]);
CurrNode->left = BuildTree(nodes);
CurrNode->right = BuildTree(nodes);
return CurrNode;
}
int KthAncestor(Node* root,int node,int k){
    if(root == NULL){
    return -1;
    }
    if(root->data == node){
        return 0;
    }
    int LeftDist = KthAncestor(root->left,node,k);
    int RightDist = KthAncestor(root->right,node,k);
    if(LeftDist != -1 && RightDist != -1){
        return -1;
    }
    int ValidVal = LeftDist == -1 ? RightDist : LeftDist;
    if(ValidVal + 1 == k){
     cout<<root->data<<" ";
    }
    return ValidVal + 1;
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
int node = 5,k = 2;
KthAncestor(root,node,k);
return 0;
}