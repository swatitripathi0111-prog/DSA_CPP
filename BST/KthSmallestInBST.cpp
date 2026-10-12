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
Node* BuildTree(int arr[],int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
     root = Insert(root,arr[i]);
    }
    return root;
}
int count = 0;
int ans = -1;
int kthSmallest(Node* root, int k) {
    if(root == NULL) return ans;
        
    int Left = kthSmallest(root->left,k);
    count++;
    if(count == k){
    ans = root->data;
    return ans;
    }
    int Right = kthSmallest(root->right,k);
    return ans;
}
int main(){
int arr[] = {5,3,7,2,4,6,8};
int n = 7;
int k = 3;
Node* root = BuildTree(arr,n);
cout<<kthSmallest(root,k)<<endl;
return 0;
}