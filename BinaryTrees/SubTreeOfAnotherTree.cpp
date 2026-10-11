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
    return  NULL;
}
Node* CurrNode = new Node(nodes[idx]);
CurrNode->left =  BuildTree(nodes);
CurrNode->right = BuildTree(nodes);
return CurrNode;
}
bool isIdentical(Node* root1,Node* root2){
   if(root1 == NULL && root2 == NULL){
      return true;
   }else if(root1 == NULL || root2 == NULL){
      return false;
   }
   if(root1->data != root2->data){
      return false;
   }
   return isIdentical(root1->left,root2->left)
          && isIdentical(root1->right,root2->right);
}
bool isSubtree(Node* root,Node* subroot){
    if(root == NULL && subroot == NULL){
        return true;
    }else if(root == NULL || subroot == NULL){
        return false;
    }
   if(root->data == subroot->data){
      if(isIdentical(root,subroot)){
        return true;
      }
   }
   int isLeftSubtree = isSubtree(root->left,subroot);
   if(!isLeftSubtree){
    return isSubtree(root->right,subroot);
   }
   return true;
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
Node* subroot = new Node(2);
subroot->left = new Node(4);
subroot->right = new Node(5);
cout<<isSubtree(root,subroot)<<endl;
return 0;
}