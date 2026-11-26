#include<iostream>
#include<vector>
using namespace std;
void Heapify(int i,vector<int> &arr,int n){
int left = 2*i+1;
int right = 2*i+2;
int MaxIdx = i;
if(left < n && arr[left] > arr[MaxIdx]){
    MaxIdx = left;
}
if(right < n && arr[right] > arr[MaxIdx]){
    MaxIdx = right;
}
if(MaxIdx != i){
 swap(arr[i],arr[MaxIdx]);
 Heapify(MaxIdx,arr,n);
}
}
void HeapSort(vector<int> &arr){
int n = arr.size();
//step1:build Max Heap
for(int i=n/2-1;i>=0;i--){
   Heapify(i,arr,n);
}
for(int i=n-1;i>=0;i--){
    swap(arr[0],arr[i]);
    Heapify(0,arr,i);
}
}
int main(){
vector<int> arr = {1,4,2,5,3};
HeapSort(arr);
for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
}
return 0;
}