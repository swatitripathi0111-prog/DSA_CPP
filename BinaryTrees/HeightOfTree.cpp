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
int Height(Node* root){
 if(root == NULL){
    return 0;
 }
 int LeftHt = Height(root->left);
 int RightHt = Height(root->right);
 int CurrHt = max(LeftHt,RightHt)+1;
 return CurrHt;
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
cout<<"Height = "<<Height(root)<<endl;
return 0;
}