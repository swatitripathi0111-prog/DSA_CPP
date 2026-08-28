#include<iostream>
#include<vector>
using namespace std;
void Merge(int *arr,int st,int mid,int end){
  vector<int> temp;
  int i = st;
  int j = mid+1;

  while(i <= mid && j <= end){
    if(arr[i] <= arr[j]){
        temp.push_back(arr[i++]);
    }else{
        temp.push_back(arr[j++]);
    }
  }
  while(i <= mid){
    temp.push_back(arr[i++]);
  }
  while(j <= end){
    temp.push_back(arr[j++]);
  }
  for(int idx=st,x=0;idx<=end;idx++){
    arr[idx] = temp[x++];
  }
}
void MergeSort(int *arr,int st,int end){
if(st >= end){
    return;
}
int mid = (st+end)/2;
MergeSort(arr,st,mid);
MergeSort(arr,mid+1,end);
Merge(arr,st,mid,end);
}
void PrintArr(int *arr,int n){
    for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
    }
}
int main(){ 
int arr[] = {6,3,7,5,2,4};
int n = 6;
MergeSort(arr,0,n-1);
PrintArr(arr,n);
 return 0;
}