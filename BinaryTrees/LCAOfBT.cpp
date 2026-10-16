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
bool FindPath(Node* root,int n,vector<int>&path){
    if(root == NULL){
    return false;
    }
    path.push_back(root->data);
    if(root->data == n){
        return true;
    }
    int isLeft = FindPath(root->left,n,path);
    int isRight = FindPath(root->right,n,path);
    if(isLeft || isRight){
        return true;
    }
    path.pop_back();
    return false;
}
int LCA1(Node* root,int n1,int n2){
    vector<int> path1;
    vector<int> path2;

    FindPath(root,n1,path1);
    FindPath(root,n2,path2);

    int lca = -1;
    for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i] != path2[j]){
            return lca;
        }
      lca = path1[i];
    }
    return lca;
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildTree(nodes);
cout<<"LCA = "<<LCA1(root,4,6)<<endl;
return 0;
}