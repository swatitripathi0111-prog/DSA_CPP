#include<iostream>
using namespace std;
void PrintArr(int *arr,int n){
    for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void InsertionSort(int *arr,int n){
    for(int i=1;i<=n-1;i++){
    int j=i;
     while(j>=1 && arr[j] < arr[j-1]){
        swap(arr[j],arr[j-1]);
        j--;
     }
    }
    PrintArr(arr,n);
}
int main(){
int arr[5] = {5,4,3,2,1};
InsertionSort(arr,5);
 return 0;
}