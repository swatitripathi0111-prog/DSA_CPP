#include<iostream>
#include<vector>
using namespace std;
void PrintArr(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int Partition(vector<int> &arr,int st,int end){
    int i = st-1;
    int pivot = arr[end];
    for(int j=st;j<end;j++){
     if(arr[j]<=pivot){
      i++;
      swap(arr[i],arr[j]);
    }
    }
    i++;
    swap(arr[i],arr[end]);
    return i;
}
void QuickSort(vector<int>&arr,int st,int end){
    if(st >= end){
    return;
    }
    int pivotIdx = Partition(arr,st,end);
    QuickSort(arr,st,pivotIdx-1);
    QuickSort(arr,pivotIdx+1,end);
}
int main(){
vector<int> arr = {6,3,7,5,2,4};
QuickSort(arr,0,arr.size()-1);
PrintArr(arr);
 return 0;
}