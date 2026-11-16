#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class SegmentTree{
    vector<int> tree;
    int n;
   void buildTree(vector<int> &arr,int start,int end,int node){
    if(start == end){
    tree[node] = arr[start];
    return;
    }
    int mid = (start+end)/2;
    buildTree(arr,start,mid,2*node+1);
    buildTree(arr,mid+1,end,2*node+2);

    tree[node] = max(tree[2*node+1] ,tree[2*node+2]);
   }
   int MaxQuery(int qi,int qj,int si,int sj,int node){
    if(qj < si || qi>sj){
    return INT_MIN;
    }
    if(si >= qi && sj <= qj){
        return tree[node];
    }
    int mid = (si+sj)/2;
    int LeftMax = MaxQuery(qi,qj,si,mid,2*node+1);
    int Rightmax = MaxQuery(qi,qj,mid+1,sj,2*node+2);
    return max(LeftMax,Rightmax);
   }
public:
   SegmentTree(vector<int> &arr){
    n = arr.size();
    tree.resize(4*n);
    buildTree(arr,0,n-1,0);
   }
   int rangeQuery(int qi,int qj){
    return MaxQuery(qi,qj,0,n-1,0);
   }
   
};
int main(){
vector<int> arr = {6,8,-1,2,17,1,3,2,4};
SegmentTree st(arr);
cout<<st.rangeQuery(2,5)<<endl;
return 0;
}