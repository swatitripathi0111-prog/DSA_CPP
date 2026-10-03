#include<iostream>
#include<queue>
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
Node* BuildTre(vector<int> nodes){
idx++;
if(nodes[idx] == -1){
return NULL;
}
Node* CurrNode = new Node(nodes[idx]);
CurrNode->left = BuildTre(nodes);
CurrNode->right = BuildTre(nodes);
return CurrNode;
}
void LevelOrderTraversal1(Node* root){
if(root == NULL){
return;
}
queue<Node*> q;
q.push(root);

while(!q.empty()){
 Node* Curr = q.front();
 q.pop();

 cout<<Curr->data<<" ";

 if(Curr->left != NULL){
    q.push(Curr->left);
 }
 if(Curr->right != NULL){
    q.push(Curr->right);
 }
}
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTre(nodes);
LevelOrderTraversal1(root);
return 0;
}     