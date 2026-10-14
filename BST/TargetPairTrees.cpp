#include<iostream>
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
Node* BuildBST(int *arr,int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
    root = Insert(root,arr[i]);
    }
    return root;
}
bool TargetPairHelper(Node* root2,int key){
    if(root2 == NULL){
     return false;
    }
    if(root2->data == key){
        return true;
    }
    if(key < root2->data){
     return TargetPairHelper(root2->left,key);
    }else{
        return TargetPairHelper(root2->right,key);
    }
}
bool TargetPair(Node* root1,Node* root2,int target){
    if(root1 == NULL){
    return false;
    }
    int RequiredNum = target-root1->data;
    if(TargetPairHelper(root2,RequiredNum)){
     return true;
    }
    if(TargetPair(root1->left,root2,target)){
        return true;
    }
    if(TargetPair(root1->right,root2,target)){
        return true;
    }
    return false;
}
int main(){
int n1 = 5;
int n2 = 5;
int arr1[] = {5,3,7,2,4};
int arr2[] = {10,6,12,1,8};
Node* root1 = BuildBST(arr1,5);
Node* root2 = BuildBST(arr2,5);
int target = 9;
if(TargetPair(root1,root2,target)){
    cout<<"pair found";
}else{
    cout<<"pair Not found";
}
return 0;
}