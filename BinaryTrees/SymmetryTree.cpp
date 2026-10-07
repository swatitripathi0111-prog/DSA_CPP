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
static int idx = -1;
Node* BuildTree(vector<int> &nodes){
idx++;
if(nodes[idx] == -1){
 return NULL;
}
Node* CurrRoot = new Node(nodes[idx]);
CurrRoot->left = BuildTree(nodes);
CurrRoot->right = BuildTree(nodes);
return CurrRoot;
}
bool Helper(Node* left,Node* right){
  if(left == NULL && right == NULL){
    return true;
  }else if(left == NULL || right == NULL){
    return false;
  }
  if(left->data != right->data){
    return false;
  }
  return Helper(left->left,right->right) &&
         Helper(left->right,right->left);
}
bool isSymmetry(Node* root){
    if(root == NULL){
       return true;
    }
    return Helper(root->left,root->right);
}

int main(){
vector<int> nodes = {1,2,3,-1,-1,4,-1,-1,2,4,-1,-1,3,-1,-1};
Node* root = BuildTree(nodes);
cout<<isSymmetry(root)<<endl;
return 0;
}