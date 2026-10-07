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
vector<int> MorrisInorderTraversal(Node* root){
    vector<int> ans;
    Node* Curr = root;

    while(Curr != NULL){
        if(Curr->left == NULL){
            ans.push_back(Curr->data);
            Curr = Curr->right;
        }else{
            Node* IP = Curr->left;
            while(IP->right != NULL && IP->right != Curr){
                IP = IP->right;
            }
            if(IP->right == NULL){
                IP->right = Curr;
                Curr = Curr->left;
            }else{
                IP->right = NULL;
                ans.push_back(Curr->data);
                Curr = Curr->right;
            }
        }
    }
    return ans;
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
vector<int> ans = MorrisInorderTraversal(root);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
return 0;
}