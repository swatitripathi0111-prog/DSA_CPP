#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int> arr){
 int n = arr.size();
 int st = 0;
 int end = n-1;
 while(st<end){
int mid = (st+end)/2;
if(mid%2 == 0){
 if(arr[mid] != arr[mid+1]){
    end = mid;
 }else{
    st = mid+1;
 }
}else{
 if(arr[mid] != arr[mid+1]){
    st = mid+1;
 }else{
    end = mid;
 }
}
 }
 return arr[st];
}

int main(){
vector<int> arr = {1,1,2,2,3,4,4,5,5};
cout<<"Single Element = "<<singleNonDuplicate(arr);
 return 0;
}