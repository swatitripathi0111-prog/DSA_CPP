#include<iostream>
#include<vector>
using namespace std;
int SearchInRotatedSortedArray(vector<int> &nums,int st,int end,int key){
if(st > end){
    return -1;
}
int mid =  (st+end)/2;
if(nums[mid] == key){
    return mid;
}
if(nums[st] <= nums[mid]){//left part sorted
  if(nums[st] <= key && key <= nums[mid]){
   return SearchInRotatedSortedArray(nums,st,mid-1,key);
  }else{
    return SearchInRotatedSortedArray(nums,mid+1,end,key);
  }
}else{//right part sorted
   if(nums[mid] <= key && key <= nums[end]){
    return SearchInRotatedSortedArray(nums,mid+1,end,key);
   }else{
     return SearchInRotatedSortedArray(nums,st,mid-1,key);
   }
}
}
int main(){
vector<int> nums = {4,5,6,7,0,1,2};
int n = nums.size();
cout<<SearchInRotatedSortedArray(nums,0,n-1,0)<<endl;
 return 0;
}