#include<iostream>
#include<vector>
#include<string>
using namespace std;
void PrintArr(vector<string> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
void Merge(vector<string> &arr,int st,int mid,int end){
   vector<string> temp;
   int i = st;
   int j = mid+1;
   while(i<=mid && j<=end){
    if(arr[i] <= arr[j]){
        temp.push_back(arr[i++]);
    }else{
         temp.push_back(arr[j++]);
    }
   }
   while(i<=mid){
     temp.push_back(arr[i++]);
   }
   while(j<=end){
     temp.push_back(arr[j++]);
   }
   for(int idx=st,x=0;idx<=end;idx++){
    arr[idx] = temp[x++];
   }
}
void MergeSort(vector<string>&arr,int st,int end){
if(st>=end){
    return;
}
int mid = (st+end)/2;
MergeSort(arr,st,mid);
MergeSort(arr,mid+1,end);
Merge(arr,st,mid,end);
}
int main(){
vector<string> arr = {"sun","earth","mars","mercury"};
MergeSort(arr,0,arr.size()-1);
PrintArr(arr);
 return 0;
}