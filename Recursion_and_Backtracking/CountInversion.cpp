#include<iostream>
#include<vector>
using namespace std;
int Merge(int *arr,int st,int mid,int end){
    vector<int> temp; 
    int i = st;
    int j = mid+1;
    int InvCount = 0;
    while(i <= mid && j <= end){
      if(arr[i] <= arr[j]){
        temp.push_back(arr[i]);
        i++;
      }else{
        temp.push_back(arr[j]);
        j++;
        InvCount += (mid-i+1);
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
    return InvCount;
}
int MergeSort(int *arr,int st,int end){
    if(st < end){
    int mid = (st+end)/2;
    int LeftCount = MergeSort(arr,st,mid);
    int RightCount = MergeSort(arr,mid+1,end);
    int InvCount = Merge(arr,st,mid,end);
    return LeftCount + RightCount + InvCount;
    }
    return 0;
}
int main(){
int arr[] = {2,4,1,3,5};
int n = 5;
int ans = MergeSort(arr,0,n-1);
cout<<"INVERSION COUNT = "<<ans;
 return 0;
}