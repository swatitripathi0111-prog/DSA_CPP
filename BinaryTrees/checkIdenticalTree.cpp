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
 bool isSameTree(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL){
        return true;
    }else if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    } 
    return isSameTree(root1->left,root2->left) &&
           isSameTree(root1->right,root2->right);
    }
int main(){
vector<int> nodes1 = {1,2,-1,-1,3,-1,-1};
vector<int> nodes2 = {1,2,-1,-1,3,-1,-1};
Node* root1 = BuildTree(nodes1);
idx = -1;
Node* root2 = BuildTree(nodes2);
cout<<isSameTree(root1,root2);
return 0;
}