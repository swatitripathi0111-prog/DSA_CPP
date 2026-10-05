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
Node* removeLeafNodes(Node* root, int target){
if(root == NULL){
    return NULL;
}
root->left = removeLeafNodes(root->left,target);
root->right = removeLeafNodes(root->right,target);
if(root->left == NULL && root->right == NULL && root->data == target){
    return NULL;
}
return root;
}
void PreorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
int main(){
vector<int> nodes = {1,2,2,-1,-1,-1,3,2,-1,-1,4,-1,-1};
Node* root = BuildTree(nodes);
removeLeafNodes(root,2);
PreorderTraversal(root);
return 0;
}