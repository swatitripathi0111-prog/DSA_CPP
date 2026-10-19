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
Node* BuildBSTFromSorrted(int arr[],int st,int end){
    if(st > end){
    return NULL;
    }
    int mid = (st+end)/2;
     Node* CurrNode = new Node(arr[mid]);
     CurrNode->left = BuildBSTFromSorrted(arr,st,mid-1);
     CurrNode->right = BuildBSTFromSorrted(arr,mid+1,end);
     return CurrNode;
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
int arr[] = {3,4,5,6,7,8,9};
Node* root = BuildBSTFromSorrted(arr,0,6);
Preorder(root);
return 0;
}