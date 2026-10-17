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
Node* CurrRoot = new Node(nodes[idx]);
CurrRoot->left = BuildTree(nodes);
CurrRoot->right = BuildTree(nodes);
return CurrRoot;
}
Node* LCA2(Node* root,int n1,int n2){
    if(root == NULL){
    return root;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* LeftLCA = LCA2(root->left,n1,n2);
    Node* RightLCA = LCA2(root->right,n1,n2);

    if(LeftLCA != NULL && RightLCA != NULL){
        return root;
    }
    return LeftLCA == NULL ? RightLCA : LeftLCA;
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
cout<<"LCA = "<<LCA2(root,4,6)->data<<endl;
return 0;
}