#include<iostream>
#include<climits>
using namespace std;
void PrintArr(int *arr,int n){
    for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void CountSort(int *arr,int n){
  int freq[1000] = {0};
  int minVal = INT_MAX;
  int MaxVal = INT_MIN;

  for(int i=0;i<n;i++){
    freq[arr[i]]++;
    minVal = min(minVal,arr[i]);
    MaxVal = max(MaxVal,arr[i]);
  }

  for(int i=minVal,j=0;i<=MaxVal;i++){
    while(freq[i]>0){
     arr[j++] = i;
     freq[i]--;
    }
  }
  PrintArr(arr,n);
}
int main(){
int arr[5] = {5,4,3,2,1};
CountSort(arr,5);
 return 0;
}