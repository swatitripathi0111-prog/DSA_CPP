#include<iostream>
#include<vector>
#include<map>
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
string solve(Node* root,vector<Node*> &ans,map<string ,int>&m){
 if(root == NULL){
    return "#";
 }
 string Left = solve(root->left,ans,m);
 string Right = solve(root->right,ans,m);
 string Curr = to_string(root->data) + "," + Left + "," + Right;
 m[Curr]++;
 if(m[Curr] == 2){
    ans.push_back(root);
 }
 return Curr;
}
vector<Node*> findDuplicateSubtrees(Node* root) {
         vector<Node*> ans;
         map<string,int> m;
         solve(root,ans,m);
         return ans; 
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,-1,3,2,4,-1,-1,-1,4,-1,-1};
Node* root = BuildTree(nodes);
vector<Node*> ans = findDuplicateSubtrees(root);
for(Node* node : ans){
    cout<<node->data<<" ";
}
return 0;
}