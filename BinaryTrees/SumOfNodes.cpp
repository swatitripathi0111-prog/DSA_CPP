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
int SumOfNode(Node* root){
    if(root == NULL){
     return 0;
    }
    int LeftSum = SumOfNode(root->left);
    int RightSum = SumOfNode(root->right);
    return LeftSum + RightSum + root->data;
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
cout<<"Sum of Nodes in BT = "<<SumOfNode(root)<<endl;
return 0;
}