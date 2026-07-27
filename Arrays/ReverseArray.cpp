#include<iostream>
using namespace std;
void PrintArray(int *arr,int n){
 for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
 }
 cout<<endl;
}
//Reversing Array without using extra space
void ReverseArrays1(int *arr,int n){
    int st = 0;
    int end = n-1;
    while(st<=end){
     swap(arr[st],arr[end]);
     st++;
     end--;
    }
    PrintArray(arr,n);
}
//Reversing Array with extra space
void ReverseArrays2(int *arr,int n){
   int CopyArr[n];
   for(int i=0;i<n;i++){
    int j = n-i-1;
    CopyArr[i] = arr[j];
   }
   for(int i=0;i<n;i++){
    arr[i] = CopyArr[i];
   }
   PrintArray(arr,n);
}
int main(){
int arr1[5] = {1,2,3,4,5};
ReverseArrays1(arr1,5);
int arr2[5] = {1,2,3,4,5};
ReverseArrays2(arr2,5);
 return 0;
}