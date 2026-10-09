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
int MaxSum = INT_MIN;
int maxSumPathHelper(Node* root){
  if(root == NULL){
    return 0;
  }
  int LeftSum = maxSumPathHelper(root->left);
  if(LeftSum < 0){
    LeftSum = 0;
  }
  int RightSum = maxSumPathHelper(root->right);
  if(RightSum < 0){
    RightSum = 0;
  }
  int Sum = root->data + LeftSum + RightSum;
  MaxSum = max(MaxSum,Sum);
  return root->data + max(LeftSum,RightSum);
}
int maxSumPath(Node* root){
   int FinalAns = maxSumPathHelper(root);
   return max(FinalAns,MaxSum);
}
int main(){
vector<int> nodes = {-10,9,-1,-1,20,15,-1,-1,7,-1,-1};
Node* root = BuildTree(nodes);
cout<<"Maximum Sum path = "<<maxSumPath(root)<<endl;
return 0;
}