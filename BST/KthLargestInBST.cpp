#include<iostream>
#include<vector>
#include<queue>
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
class KthLargest{
public:
int k;
vector<int> nums;
priority_queue<int,vector<int>,greater<int>> pq;

KthLargest(int k, vector<int>& nums) {
this->k = k;
this->nums = nums;

for(int i=0;i<nums.size();i++){
pq.push(nums[i]);
}
}
int add(int val) {
nums.push_back(val);
pq.push(val);
while(pq.size() > k){
pq.pop();
}
return pq.top();
}
};
int main(){
vector<int> nums = {4,5,8,2};
KthLargest obj(3,nums);
cout<<obj.add(3)<<endl;
cout<<obj.add(5)<<endl;
cout<<obj.add(10)<<endl;
cout<<obj.add(9)<<endl;
cout<<obj.add(4)<<endl;
return 0;
}