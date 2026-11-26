#include<iostream>
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
Node* nextRight = NULL;
Node* Left = NULL;
void Helper(Node* root){
    if(root == NULL){
        return;
    }
    Helper(root->right);
    Left = root->left;
    root->left = NULL;
    root->right = nextRight;
    nextRight = root;
    Helper(Left);
}
Node* FlattenBST(Node* root){
   Helper(root);
   return nextRight;
}
int main(){
Node* root = new Node(5);
root->left = new Node(3);
root->left->left = new Node(2);
root->left->right = new Node(4);

root->right = new Node(7);
root->right->left = new Node(6);
root->right->right = new Node(8);

Node* head = FlattenBST(root);

Node* temp = head;
while(temp != NULL){
  cout<<temp->data<<"->";
  temp = temp->right;
}
cout<<"NULL\n";
return 0;
}