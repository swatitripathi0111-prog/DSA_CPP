#include<iostream>
#include<vector>
#include<queue>
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
int MaxLevelSum(Node* root){
queue<Node*> q;
q.push(root);
q.push(NULL);
int MaxSum = INT_MIN;
int sum = 0;
int CurrLevel = 1;
int ans = -1;

while(!q.empty()){
    Node* Curr = q.front();
    q.pop();
    if(Curr == NULL){
    if(sum > MaxSum){
     ans = CurrLevel;
    }
    MaxSum = max(MaxSum,sum);
    sum = 0;
      if(q.empty()){
        break;
      }
      q.push(NULL);
      CurrLevel++;
    }else{
      sum = sum + Curr->data;
      if(Curr->left != NULL){
        q.push(Curr->left);
      }
      if(Curr->right != NULL){
        q.push(Curr->right);
      }
    }
}
 return ans;
}
int main(){
vector<int> nodes = {1,7,7,-1,-1,-8,-1,-1,0,-1,-1};
Node* root = BuildTree(nodes);
cout<<"Maximum Level Sum = "<<MaxLevelSum(root)<<endl;
return 0;
}