#include<iostream>
#include<vector>
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
     int idx = 0;
     Node* bstFromPreorderHelper(vector<int>& preorder,int min,int max){
        int n = preorder.size();
        if(idx >= n){
            return NULL;
        }
         if(min > preorder[idx]  || max < preorder[idx]){
            return NULL;
         }
         Node* CurrRoot = new Node(preorder[idx]);
         idx++;
         CurrRoot->left = bstFromPreorderHelper(preorder,min,CurrRoot->data);
         CurrRoot->right = bstFromPreorderHelper(preorder,CurrRoot->data,max);
         return CurrRoot;
     }
    Node* bstFromPreorder(vector<int>& preorder) {
      return bstFromPreorderHelper(preorder,INT_MIN,INT_MAX);
    }
int main(){
vector<int> preorder = {8,5,1,7,10,12};
Node* root = bstFromPreorder(preorder);
return 0;
}