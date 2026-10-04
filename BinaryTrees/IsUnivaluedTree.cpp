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
Node* CurrRoot = new Node(nodes[idx]);
CurrRoot->left = BuildTree(nodes);
CurrRoot->right = BuildTree(nodes);
return CurrRoot;
}
bool isUnivalTree(Node* root) {
    if(root == NULL) return true;
    if(root->left != NULL && root->data != root->left->data){
        return false;
    }
    if(root->right != NULL && root->data != root->right->data){
        return false;
    }
    return  isUnivalTree(root->left) && isUnivalTree(root->right);}
int main(){
vector<int> nodes = {1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1};
Node* root = BuildTree(nodes);
cout<<isUnivalTree(root)<<endl;
return 0;
}