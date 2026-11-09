#include<iostream>
#include<stack>
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
class BSTIterator{
public:
stack<Node*> s;
void Inorder(Node* root,stack<Node*> &s){
   Node* Curr = root;
   while(Curr != NULL){
      s.push(Curr);
      Curr = Curr->left;
   }
}
BSTIterator(Node* root) {
   Inorder(root,s);
} 
int next() {
Node* node = s.top();
int ans = node->data;
s.pop();
if(node->right != NULL){
   node = node->right;
   Inorder(node,s);
}
return ans;
}
bool hasNext() {
return !s.empty();
}
};
int main(){
int arr[] = {5,1,3,4,2,7};
Node* root = BuildBST(arr,6);
BSTIterator it(root);

while(it.hasNext()){
   cout << it.next() << " ";
}

return 0;
}
