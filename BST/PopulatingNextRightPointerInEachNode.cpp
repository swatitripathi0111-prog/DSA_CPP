#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
  int data;
  Node* left;
  Node* right;
  Node* next;
  Node(int data){
    this->data = data;
    left = right = next = NULL;
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
Node* connect(Node* root) {
if(root == NULL){
return NULL;
}
queue<Node*> q;
q.push(root);
q.push(NULL);
root->next = NULL;
Node* prev = NULL;

while(!q.empty()){
    Node* Curr = q.front();
    q.pop();
    if(Curr == NULL){
    prev = NULL;
    if(q.empty()){
    break;
    }
    q.push(NULL);
    }else{
    if(prev != NULL){
    prev->next = Curr;
    Curr->next = NULL;
    }
    prev = Curr;
    if(Curr->left != NULL){
        q.push(Curr->left);
    }
    if(Curr->right != NULL){
    q.push(Curr->right);
    }
    }
}
return root;
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
Node* root = BuildTree(nodes);
Node* ans = connect(root);
return 0;
}