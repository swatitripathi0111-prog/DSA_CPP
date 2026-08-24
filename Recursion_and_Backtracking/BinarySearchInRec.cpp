#include<iostream>
using namespace std;
int BinarySearchInRec(int *nums,int st,int end,int target){
  if(st>end){
    return -1;
  }
  int mid = (st+end)/2;
  if(nums[mid] == target){
    return mid;
  }else if(nums[mid] < target){
    return BinarySearchInRec(nums,mid+1,end,target);
  }else{
    return BinarySearchInRec(nums,st,mid-1,target);
  }
}
int main(){
int n = 7;
int nums[7] = {1,2,3,4,5,6,7};
cout<<BinarySearchInRec(nums,0,n-1,5);
 return 0;
}