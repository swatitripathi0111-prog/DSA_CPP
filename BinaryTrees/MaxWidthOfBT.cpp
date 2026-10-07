#include<iostream>
#include<vector>
#include<queue>
#include<climits>
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
int widthOfBinaryTree(Node* root) {
    queue<pair<Node*,long long>> q;
    q.push(make_pair(root,0));
    q.push(make_pair((Node*)NULL,-1));
    pair<Node*,long long> first;
    pair<Node*,long long> prev;
    int MaxWidth = INT_MIN;
    first = q.front();
    while(!q.empty()){
      pair<Node*,long long> Curr = q.front();
      q.pop();

      if(Curr.first == NULL){
        int Width = prev.second - first.second + 1;
        MaxWidth = max(MaxWidth,Width);
        if(q.empty()){
            break;
        }
        first = q.front();
         q.push(make_pair((Node*)NULL,-1));
      }else{
        prev = Curr;
        if(Curr.first->left != NULL){
          q.push(make_pair(Curr.first->left,2*Curr.second+1));
        }
        if(Curr.first->right != NULL){
          q.push(make_pair(Curr.first->right,2*Curr.second+2));
        }
      }
    }
    return MaxWidth;
}
int main(){
vector<int> nodes = {1,3,5,-1,-1,3,-1,-1,2,-1,9,-1,-1};
Node* root = BuildTree(nodes);
cout<<"Maximum width of BT = "<<widthOfBinaryTree(root)<<endl;
return 0;
}