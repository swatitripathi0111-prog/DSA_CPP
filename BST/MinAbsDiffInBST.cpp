#include<iostream>
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
Node* insert(Node* root,int val){
   if(root == NULL){
    root = new Node(val);
    return root;
   }
   if(val < root->data){
    root->left = insert(root->left,val);
   }else{
    root->right = insert(root->right,val);
   }
   return root;
} 
Node* BuildBST(int arr[],int n){
   Node* root = NULL;
   for(int i=0;i<n;i++){
    root = insert(root,arr[i]);
   }
   return root;
}
int MinDiff = INT_MAX;
Node* ans;
Node* AbsDiff(Node* root,int k){
    if(root == NULL){
    return root;
    }
    int diff = abs(root->data-k);
    if(diff < MinDiff){
    MinDiff = diff;
    ans = root;
    }
    if(root->data > k){
        AbsDiff(root->left,k);
    }else{
        AbsDiff(root->right,k);
    }
    return ans;
}
int main(){
int arr[] = {5,1,3,4,2,7};
Node* root = BuildBST(arr,6);
cout<<AbsDiff(root,6)->data<<endl;
return 0;
}