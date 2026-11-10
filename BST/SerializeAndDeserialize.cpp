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
Node* BuildTree(vector<int> &nodes,int &idx){
idx++;
if(nodes[idx] == -1){
    return NULL;
}
Node* CurrNode = new Node(nodes[idx]);
CurrNode->left = BuildTree(nodes,idx);
CurrNode->right = BuildTree(nodes,idx);
return CurrNode;
}
// Encodes a tree to a single string.
void SerHelper(Node* root,string &ans){
   if(root == NULL){
     ans += "NULL,";
     return;
   }
   ans += to_string(root->data) +",";
   SerHelper(root->left,ans);
   SerHelper(root->right,ans);
}
string serialize(Node* root){
    string ans = "";
    SerHelper(root,ans);
    return ans;
}
// Decodes your encoded data to tree.
Node* DesHelper(vector<string> &v,int &idx){
idx++;
if(v[idx] == "NULL"){
    return NULL;
}
Node* Curr = new Node(stoi(v[idx]));
Curr->left = DesHelper(v,idx);
Curr->right = DesHelper(v,idx);
return Curr;
}
Node* deserialize(string data){
vector<string> v;
string temp = "";
for(int i=0;i<data.size();i++){
    if(data[i] == ','){
        v.push_back(temp);
        temp = "";
    }else{
        temp += data[i];
    }
}
 v.push_back(temp);
 int idx = -1;
 return DesHelper(v,idx);
}
// Preorder Traversal
void Preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
int idx = -1;
Node* root = BuildTree(nodes,idx);
string ans = serialize(root);
cout << "Serialized: " << ans << endl;
Node* newRoot = deserialize(ans);
cout << "Original Tree: ";
Preorder(root);
cout << "\nDeserialized Tree: ";
Preorder(newRoot);
return 0;
}