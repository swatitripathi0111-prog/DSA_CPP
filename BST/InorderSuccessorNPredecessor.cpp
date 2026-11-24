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
Node* rightMostInLeftSubtree(Node* root){
  Node* ans;
  while(root != NULL){
    ans = root;
    root = root->right;
  }
  return ans;
}
Node* leftMostInRightSubtree(Node* root){
 Node* ans;
  while(root != NULL){
    ans = root;
    root = root->left;
  }
  return ans;
}
vector<int> getPredSucc(Node* root,int key){
  Node* Curr = root;
  Node* pred = NULL;
  Node* Succ = NULL;

  while(Curr != NULL){
    if(key < Curr->data){
      Succ = Curr;
      Curr = Curr->left;
    }else if(key >  Curr->data){
        pred = Curr;
        Curr = Curr->right;
    }else{
      if(Curr->left != NULL){
        pred = rightMostInLeftSubtree(Curr->left);
      }
      if(Curr->right != NULL){
        Succ = leftMostInRightSubtree(Curr->right);
      }
      break;
    }
  }
  return {pred->data,Succ->data};
}
int main(){
Node* root = new Node(6);
root->left = new Node(4);
root->right = new Node(8);
root->left->left = new Node(1);
root->left->right = new Node(5);
root->right->left = new Node(7);
root->right->right = new Node(9);

int key = 7;
vector<int> ans = getPredSucc(root,key);
cout<<"Predecessor = "<<ans[0]<<endl;
cout<<"Successor = "<<ans[1]<<endl;
return 0;
}