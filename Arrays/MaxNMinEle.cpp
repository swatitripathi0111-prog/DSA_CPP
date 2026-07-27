#include<iostream>
using namespace std;
void LargestElement(int *arr,int n){
    int max = arr[0];
    int min = arr[0];
    for(int i=0;i<n;i++){
     if(arr[i] > max){
     max = arr[i];
     }
     if(arr[i] < min){
        min = arr[i];
     }
    }
    cout<<"Maximum element = "<<max<<endl;
    cout<<"Minimum element = "<<min<<endl;
}
int main(){
int arr[] = {5,4,3,9,12};
LargestElement(arr,5);
 
 return 0;
}