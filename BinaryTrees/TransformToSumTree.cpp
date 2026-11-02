#include<iostream>
#include<vector>
#include<queue>
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
int TransformTree(Node* root){
    if(root == NULL){
    return 0;
    }
    int LeftOld = TransformTree(root->left);
    int RightOld = TransformTree(root->right);
    int CurrOld = root->data;
    root->data = LeftOld + RightOld;
    if(root->left != NULL){
    root->data += root->left->data;
    }
    if(root->right != NULL){
    root->data += root->right->data;
    }
    return CurrOld;
}
void LevelOrderTraversal2(Node* root){
    if(root == NULL){
    return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
     Node* Curr = q.front();
     q.pop();
     if(Curr == NULL){
       cout<<endl;
       if(q.empty()){
        break;
       }
       q.push(NULL);
     }else{
        cout<<Curr->data<<" ";
        if(Curr->left != NULL){
          q.push(Curr->left);
        }
        if(Curr->right != NULL){
         q.push(Curr->right);
        }
     }
    }
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
TransformTree(root);
LevelOrderTraversal2(root);
return 0;
}