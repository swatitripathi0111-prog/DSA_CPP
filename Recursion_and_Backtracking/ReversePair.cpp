#include<iostream>
#include<vector>
using namespace std;
int Merge(vector<int>&arr,int st,int mid,int end){
    vector<int> temp;
    int i = st;
    int j = mid+1;
    int ReversePair = 0;
    while(i<=mid && j<=end){
    if(arr[i] > 2*arr[j]){
     j++;
     ReversePair += (mid-i+1);
    }else{
    i++;
    }
    }
    i = st;
    j = mid+1;
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
    return ReversePair;
}
int MergeSort(vector<int>&arr,int st,int end){
 if(st<end){
 int mid = (st+end)/2;
  int LeftCount = MergeSort(arr,st,mid);
 int RightCount = MergeSort(arr,mid+1,end);
 int RevCount = Merge(arr,st,mid,end);
 return LeftCount + RightCount + RevCount;
 }
 return 0;
}
int main(){
vector<int> arr = {1,3,2,3,1};//output = 2;
int ans = MergeSort(arr,0,arr.size()-1);
cout<<"Number of Reverse pairs = "<<ans<<endl;
return 0;
}