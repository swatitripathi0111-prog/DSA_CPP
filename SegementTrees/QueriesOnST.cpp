 #include<iostream>
#include<vector>
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

    tree[node] = tree[2*node+1] + tree[2*node+2];
   }
   int RangeSum(int qi,int qj,int si,int sj,int node){
    if(qj < si || qi>sj){
    return 0;
    }
    if(si >= qi && sj <= qj){
        return tree[node];
    }
    int mid = (si+sj)/2;
    return RangeSum(qi,qj,si,mid,2*node+1)+ RangeSum(qi,qj,mid+1,sj,2*node+2);
   }
public:
   SegmentTree(vector<int> &arr){
    n = arr.size();
    tree.resize(4*n);
    buildTree(arr,0,n-1,0);
   }
   int rangeQuery(int qi,int qj){
    return RangeSum(qi,qj,0,n-1,0);
   }
};
int main(){
vector<int> arr = {1,2,3,4,5,6,7,8};
SegmentTree st(arr);
cout<<st.rangeQuery(2,5)<<endl;
cout<<st.rangeQuery(0,3)<<endl;
cout<<st.rangeQuery(6,7)<<endl;
return 0;
}