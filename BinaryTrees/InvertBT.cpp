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
Node* InvertTree(Node* root){
    if(root == NULL){
        return NULL;
    }
    swap(root->left,root->right);
    Node* LeftInv = InvertTree(root->left);
    Node* RightInv = InvertTree(root->right);
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
vector<int> nodes = {4,2,1,-1,-1,3,-1,-1,7,6,-1,-1,9,-1,-1};
Node* root = BuildTree(nodes);
InvertTree(root);
PreorderTraversal(root);
return 0;
}