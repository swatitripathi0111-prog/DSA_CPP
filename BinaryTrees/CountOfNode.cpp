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
int CountofNodes(Node* root){
    if(root == NULL){
     return 0;
    }
    int LeftCount = CountofNodes(root->left);
    int RightCount = CountofNodes(root->right);
    return LeftCount + RightCount + 1;
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
cout<<"Count = "<<CountofNodes(root)<<endl;
return 0;
}