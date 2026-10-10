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
pair<int,int> Diameter2(Node* root){
  if(root == NULL){
    return make_pair(0,0);
  }
  pair<int,int> LeftInfo = Diameter2(root->left);
  pair<int,int> RightInfo = Diameter2(root->right);
  int CurrDia = LeftInfo.second + RightInfo.second + 1;
  int FinalDia = max(CurrDia,max(LeftInfo.first,RightInfo.first));
  int FinalHt = max(LeftInfo.second,RightInfo.second) + 1;
  return make_pair(FinalDia,FinalHt);
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
cout<<"Diameter = "<<Diameter2(root).first<<endl;
return 0;
}