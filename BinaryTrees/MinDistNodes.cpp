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
void InorderTraversal(Node* root,vector<int> &ans){
    if(root == NULL){
     return;
    }
    InorderTraversal(root->left,ans);
    ans.push_back(root->data);
    InorderTraversal(root->right,ans);
}
int MinDiff(Node* root){
  vector<int>ans;
  InorderTraversal(root,ans);
  int MinDiff = INT_MAX;
  int  i = 0;
  int j = 1;
  while(j != ans.size()){
    int diff = ans[j]-ans[i];
    MinDiff = min(MinDiff,diff);
    i++;
    j++;
  }
  return MinDiff;
}

int main(){
vector<int> nodes = {4,2,1,-1,-1,3,-1,-1,6,-1,-1};
Node* root = BuildTree(nodes);
cout<<"Min Diff = "<<MinDiff(root)<<endl;
return 0;
}