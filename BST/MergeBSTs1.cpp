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
Node* BSTFromSortedVec(vector<int> &arr,int st,int end){
    if(st > end){
     return NULL;
    }
    int mid = (st+end)/2;
    Node* Curr = new Node(arr[mid]);
    Curr->left = BSTFromSortedVec(arr,st,mid-1);
    Curr->right = BSTFromSortedVec(arr,mid+1,end);
    return Curr;
}
void GetInorder(vector<int>& nodes,Node* root){
if(root == NULL){
    return;
}
GetInorder(nodes,root->left);
nodes.push_back(root->data);
GetInorder(nodes,root->right);
}
Node* MergeBSTs(Node* root1,Node* root2){
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    GetInorder(nodes1,root1);
    GetInorder(nodes2,root2);

    int i=0;
    int j=0;
    while(i<nodes1.size() && j<nodes2.size()){
      if(nodes1[i] <= nodes2[j]){
       merged.push_back(nodes1[i++]);
      }else{
       merged.push_back(nodes2[j++]); 
      }
    }
    while(i<nodes1.size()){
    merged.push_back(nodes1[i++]);
    }
    while(j<nodes2.size()){
    merged.push_back(nodes2[j++]);
    }
    return BSTFromSortedVec(merged,0,merged.size()-1);
}
void Preorder(Node* root){
if(root == NULL){
    return;
}
cout<<root->data<<" ";
Preorder(root->left);
Preorder(root->right);
}
int main(){
Node* root1 = new Node(2);
root1->left = new Node(1);
root1->right = new Node(4);

Node* root2 = new Node(9);
root2->left = new Node(3);
root2->right = new Node(12);
Node* root = MergeBSTs(root1,root2);
Preorder(root);
return 0;
}