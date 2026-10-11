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
Node* CurrNode = new Node(nodes[idx]);
CurrNode->left = BuildTree(nodes);
CurrNode->right = BuildTree(nodes);
return CurrNode;
}    
pair<int,bool> isBalancedHelper(Node* root) {
        if(root == NULL){
        return make_pair(0,true);
        }
        pair<int,bool> LeftInfo = isBalancedHelper(root->left);
        pair<int,bool> RightInfo = isBalancedHelper(root->right);

         int condition = abs(LeftInfo.first-RightInfo.first);

         if(condition <= 1 && (LeftInfo.second && RightInfo.second)){
            return make_pair(max(LeftInfo.first,RightInfo.first)+1,true);
        }
        return make_pair(max(LeftInfo.first,RightInfo.first)+1,false);
}
bool isBalanced(Node* root) {
    return isBalancedHelper(root).second;
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
cout<<isBalanced(root)<<endl;
return 0;
}