#include<iostream>
#include<vector>
using namespace std;
class SegmentTree{
    vector<int> tree;
    int n;
public:
   SegmentTree(vector<int> &arr){
    n = arr.size();
    tree.resize(4*n);
    buildTree(arr,0,n-1,0);
   }
   void buildTree(vector<int> &arr,int start,int end,int node){
    if(start == end){
    tree[node] = arr[start];
    return;
    }
    int mid = (start+end)/2;
    buildTree(arr,start,mid,2*node+1);
    buildTree(arr,mid+1,end,2*node+2);

    tree[node] = tree[2*node+1] + tree[2*node+2];
   }
   void PrintTree(){
    for(int i=0;i<tree.size();i++){
    cout<<tree[i]<<" ";
    }
    cout<<endl;
   }
};
int main(){
vector<int> arr = {1,2,3,4,5,6,7,8};
SegmentTree st(arr);
st.PrintTree();
return 0;
}