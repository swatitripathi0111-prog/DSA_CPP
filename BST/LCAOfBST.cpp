#include<iostream>
using namespace std;
class Node{
public: 
   int val;
   Node* left;
   Node* right;
   Node(int data){
    val = data;
    left = right = NULL;
   }
};
Node* insert(Node* root,int val){
   if(root == NULL){
    root = new Node(val);
    return root;
   }
   if(val < root->val){
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
Node* LCAOfBST(Node* root,Node* p,Node* q){
if(root == NULL){
     return NULL;
    }
    if(root->val > p->val && root->val > q->val){
        return LCAOfBST(root->left,p,q);
    }else if(root->val < p->val && root->val < q->val){
        return LCAOfBST(root->right,p,q);
    }else{
        return root;
    }
}
int main(){
    int arr[] = {5,1,3,4,2,7};
    Node* root = BuildBST(arr,6);

    Node* p = new Node(1);
    Node* q = new Node(4);

    Node* ans = LCAOfBST(root,p,q);

    if(ans != NULL){
        cout << "LCA = " << ans->val;
    }
    return 0;
}