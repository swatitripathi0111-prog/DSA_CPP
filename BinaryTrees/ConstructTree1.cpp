#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
   int val;
   Node* left;
   Node* right;
   Node(int data){
    this->val = data;
    left = right = NULL;
   }
};
Node* constructTree(vector<int>& preorder, vector<int>& inorder, int st, int end,int &idx) {
    if(st > end) return NULL;
    Node* currNode = new Node(preorder[idx]);
    idx++;
    int j = 0;
    for(int i = st; i <= end; i++) {
        if(currNode->val == inorder[i]) {
            j = i;
            break;
        }
    }
    currNode->left = constructTree(preorder, inorder, st, j-1,idx);
    currNode->right = constructTree(preorder, inorder, j+1, end,idx);
    return currNode;
}   
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return constructTree(preorder,inorder,0, preorder.size()-1,idx);
}
int main(){
vector<int> preorder = {3,9,20,15,7};
vector<int> inorder = {9,3,15,20,7};
Node* root = buildTree(preorder,inorder); 
return 0;
}