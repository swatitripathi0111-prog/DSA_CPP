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
void KthLevelHelper(Node* root,int k,int CurrLevel){
    if(root == NULL){
        return;
    }
    if(CurrLevel == k){
     cout<<root->data<<" ";
     return;
    }
    KthLevelHelper(root->left,k,CurrLevel+1);
    KthLevelHelper(root->right,k,CurrLevel+1);

}
void KthLevel(Node* root,int k){
    KthLevelHelper(root,3,1);
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
KthLevel(root,3);
return 0;
}