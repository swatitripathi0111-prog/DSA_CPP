#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
vector<vector<int>> zigzagLevelOrder(Node* root){
 if(root == NULL){
    return {};
 }
 queue<Node*> q;
 q.push(root);
 q.push(NULL);
 int count = 0;
 vector<vector<int>> ans;
 vector<int> level;
 
 while(!q.empty()){
    Node* Curr = q.front();
    q.pop();

    if(Curr == NULL){
        if(count%2 == 0){
          ans.push_back(level);
        }else{
          reverse(level.begin(),level.end());
          ans.push_back(level);
        }
        count++;
        level.clear();
        if(q.empty()){
            break;
        }
        q.push(NULL);
    }else{
     level.push_back(Curr->data);

     if(Curr->left != NULL){
        q.push(Curr->left);
     }
     if(Curr->right != NULL){
        q.push(Curr->right);
     }
    }
 }
 return ans;
}     
int main(){
vector<int> nodes = {3,9,-1,-1,20,15,-1,-1,7,-1,-1};
Node* root = BuildTree(nodes);
vector<vector<int>> ans = zigzagLevelOrder(root);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}