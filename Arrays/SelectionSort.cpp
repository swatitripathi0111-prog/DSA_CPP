#include<iostream>
#include<climits>
using namespace std;
void PrintArr(int *arr,int n){
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
  cout<<endl;
}
void SeletionSort(int *arr,int n){
   for(int i=0;i<n-1;i++){
    int MinNum = INT_MAX;
    int minIdx = -1;
    for(int j=i;j<n;j++){
      if(MinNum > arr[j]){
        MinNum = arr[j];
        minIdx = j;
      }
    } 
    swap(arr[i],arr[minIdx]);
   }
   PrintArr(arr,n);
}
int main(){
int arr[5] = {5,4,3,2,1};
SeletionSort(arr,5);
return 0;
}