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
static int idx = -1;
Node* BuildBT(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1){
      return NULL;
    }
    Node* CurrNode = new Node(nodes[idx]);
    CurrNode->left = BuildBT(nodes);
    CurrNode->right = BuildBT(nodes);
    return CurrNode;
}
Node* LCA(Node* root,int n1,int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* LeftLCA = LCA(root->left,n1,n2);
    Node* RightLCA = LCA(root->right,n1,n2);

    if(LeftLCA != NULL && RightLCA != NULL){
        return root;
    }
    return LeftLCA == NULL ? RightLCA : LeftLCA;
}
int Distance(Node* root,int n){
    if(root == NULL){
    return -1;
    }
    if(root->data == n){
    return 0;
    }
    int LeftDist = Distance(root->left,n);
    if(LeftDist != -1){
     return LeftDist + 1;
    }
    int rightDist = Distance(root->right,n);
    if(rightDist != -1){
        return rightDist + 1;
    }
    return -1;
}
int MinDis(Node* root,int n1,int n2){
    Node* lca =  LCA(root,n1,n2);
    return Distance(lca,n1) + Distance(lca,n2);
}
int main(){
vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = BuildBT(nodes);
cout<<"MINIMUM DISTANCE = "<<MinDis(root,4,6)<<endl;
return 0;
}