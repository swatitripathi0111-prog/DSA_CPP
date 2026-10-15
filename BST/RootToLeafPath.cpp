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
Node* Insert(Node* root,int val){
    if(root == NULL){
     root = new Node(val);
     return root;
    }
    if(val < root->data){
     root->left = Insert(root->left,val);
    }else{
    root->right = Insert(root->right,val);
    }
    return root;
}
Node* BuildBST(int arr[],int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
     root = Insert(root,arr[i]);
    }
    return root;
}
void PrintPath(vector<int> path){
    cout<<"Path : ";
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void PathHelper(Node* root,vector<int> &path){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        PrintPath(path);
        path.pop_back();
        return;
    }
    PathHelper(root->left,path);
    PathHelper(root->right,path);
    path.pop_back();
}
void RootToLeaf(Node* root){
    vector<int> path;
    PathHelper(root,path);
}
int main(){
int arr[] = {5,1,3,4,2,7};
Node* root = BuildBST(arr,6);
RootToLeaf(root);
return 0;
}