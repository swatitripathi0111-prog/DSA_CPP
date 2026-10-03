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
Node* BuildTree(vector<int> &nodes){
idx++;
if(nodes[idx] == -1){
    return NULL;
}
Node* CurrNode = new Node(nodes[idx]);
CurrNode->left = BuildTree(nodes);
CurrNode->right = BuildTree(nodes);
return CurrNode;
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
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
cout<<"Inorder : "<<endl;
Inorder(root);
return 0;
}
