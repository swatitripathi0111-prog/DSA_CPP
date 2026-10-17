#include<iostream>
#include<vector>
#include<map>
#include<queue>
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
Node* Curr = new Node(nodes[idx]);
Curr->left = BuildTree(nodes);
Curr->right = BuildTree(nodes);
return Curr;
}
void BottomView(Node* root){
queue<pair<Node*,int>> q;
map<int,int> m;
q.push(make_pair(root,0));

while(!q.empty()){
    pair<Node*,int> Curr = q.front();
    q.pop();
    
    Node* CurrNode = Curr.first;
    int CurrHD = Curr.second;

    m[CurrHD] = CurrNode->data;
    
    if(CurrNode->left != NULL){
     q.push(make_pair(CurrNode->left,CurrHD-1));
    }
    if(CurrNode->right != NULL){
    q.push(make_pair(CurrNode->right,CurrHD+1));
    }
   }
for(auto it : m){
 cout<<it.second<<" ";
}
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
BottomView(root);
return 0;
}
