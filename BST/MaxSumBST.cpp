#include<iostream>
#include<climits>
using namespace std;
class Node{
public: 
   int val;
   Node* left;
   Node* right;
   Node(int data){
    this->val = data;
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
class Info{
public:
   bool isBST;
   int min;
   int max;
   int sum;
   Info(bool isBST,int min,int max,int sum){
    this->isBST = isBST;
    this->min = min;
    this->max = max;
    this->sum = sum;
   }
};
int MaxSum = 0;
Info* LargestBST(Node* root){
if(root == NULL){
return new Info(true,INT_MAX,INT_MIN,0);
}
Info* leftInfo = LargestBST(root->left);
Info* RightInfo = LargestBST(root->right);
int CurrMin = min(root->val,min(leftInfo->min,RightInfo->min));
int CurrMax = max(root->val,max(leftInfo->max,RightInfo->max));
int CurrSum = leftInfo->sum + RightInfo->sum + root->val;
if(leftInfo->isBST && RightInfo->isBST && root->val > leftInfo->max && RightInfo->min > root->val){
    MaxSum = max(CurrSum,MaxSum);
    return new Info(true,CurrMin,CurrMax,CurrSum);
}
 return new Info(false,CurrMin,CurrMax,CurrSum);
}
int maxSumBST(Node* root) {
    LargestBST(root);
    return MaxSum;
}
int main(){
int arr[] = {5,1,3,4,2,7};
Node* root = BuildBST(arr,6);
cout<<maxSumBST(root)<<endl;
return 0;
}