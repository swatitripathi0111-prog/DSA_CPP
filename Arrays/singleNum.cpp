#include<iostream>
using namespace std;
int SingleNum(int *arr,int n){
    int result = 0;
    for(int i=0;i<n;i++){
    result = result^arr[i];
    }
    return result;
}
int main(){
int arr[] = {4,1,2,1,2};
cout<<SingleNum(arr,5);
return 0;
}