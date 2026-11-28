#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<climits>
using namespace std;
class TreeNode{
public:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val){
    this->val = val;
    left = right = NULL;
  }
};
unordered_map<int, TreeNode*> mp;
unordered_set<int> leaves;
bool valid = true;
TreeNode* solve(TreeNode* root, long long low, long long high) {
    if (root == NULL){
        return NULL;
    }
    // Check BST condition
    if (root->val <= low || root->val >= high){
        valid = false;
        return NULL;
    }
    // If current node is a leaf
    if (root->left == NULL && root->right == NULL) {
        // Check if another BST has same root value
        if (mp.count(root->val) == 1) {
            TreeNode* temp = mp[root->val];
            root->left = temp->left;
            root->right = temp->right;
            mp.erase(root->val);
    }
    }
    root->left = solve(root->left, low, root->val);
    root->right = solve(root->right, root->val, high);
    return root;
}
TreeNode* canMerge(vector<TreeNode*>& trees) {
    // Store all roots
    for (auto root : trees) {
        mp[root->val] = root;
        if (root->left != NULL){
        leaves.insert(root->left->val);
        }
        if (root->right != NULL){
        leaves.insert(root->right->val);
        }
    }
// Find final root
TreeNode* root = NULL;
for (auto node : trees) {
    if (leaves.count(node->val) == 0) {
        if (root != NULL){
            return NULL;
        }
        root = node;
    }
}
if (root == NULL){
        return NULL;
}
mp.erase(root->val);
valid = true;
// Merge and validate
TreeNode* ans = solve(root, LLONG_MIN, LLONG_MAX);
if(!valid || !mp.empty()){
    return NULL;
}
// All trees must be merged
if (ans == NULL || !mp.empty()){
    return NULL;
}
return ans;
}
void Inorder(TreeNode* root){
if(root == NULL){
    return;
}
Inorder(root->left);
cout<<root->val<<" ";
Inorder(root->right);
}
int main(){
TreeNode* root1 = new TreeNode(2);
root1->left = new TreeNode(1);
root1->right = new TreeNode(3);

TreeNode* root2 = new TreeNode(3);
root2->left = NULL;
root2->right = new TreeNode(4);
vector<TreeNode*> trees;
trees.push_back(root1);
trees.push_back(root2);
TreeNode* FinalRoot = canMerge(trees);
Inorder(FinalRoot);
return 0;
}