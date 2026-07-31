#include<iostream>
using namespace std;
void PrintArr(int *arr,int n){
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
  cout<<endl;
}
void BubbleSort(int *arr,int n){
   for(int i=0;i<n-1;i++){
     bool isswap = false;
     for(int j=0;j<n-i-1;j++){
        if(arr[j] > arr[j+1]){
          swap(arr[j],arr[j+1]);
          isswap = true;
        }
     }
     if(!isswap){
        PrintArr(arr,n);
        return;
     }
   }
   PrintArr(arr,n);
}
int main(){
int arr[5] = {5,4,3,2,1};
BubbleSort(arr,5);
return 0;
}