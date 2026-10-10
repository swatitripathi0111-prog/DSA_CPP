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
Node* constructTree(vector<int>& inorder, vector<int>& postorder, int st, int end,int &idx) {
    if(st > end) return NULL;
    Node* currNode =  new Node(postorder[idx]);
    idx--;
    int j = 0;
    for(int i = st; i <= end; i++) {
        if(currNode->val == inorder[i]) {
            j = i;
            break;
        }
    }
    currNode->right = constructTree(inorder,postorder, j+1, end,idx);
    currNode->left = constructTree(inorder,postorder, st, j-1,idx);
    return currNode;
}
    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
     return constructTree(inorder,postorder,0,postorder.size()-1,idx);   
    }
int main(){
vector<int> postorder = {9,15,7,20,3};
vector<int> inorder = {9,3,15,20,7};
Node* root = buildTree(inorder,postorder);
return 0;
}