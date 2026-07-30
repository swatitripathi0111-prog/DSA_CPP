#include<iostream>
#include<vector>
using namespace std;
int RotatedArray(vector<int> nums,int target){
    int n = nums.size();
    int st = 0;
    int end = n-1;

    while(st<=end){
    int mid = (st+end)/2;
    if(nums[mid] == target){
      return mid;
    }
    if(nums[st] <= nums[mid]){ //left half sorted
        if(nums[st] <= target && target <= nums[mid]){
            end = mid -1;
        }else{
            st = mid+1;
        }
    }else{//right half sorted
        if(nums[mid] <= target && target <= nums[end]){
            st = mid+1;
        }else{
            end = mid-1;
        }
    }
    }
    return -1;
}
int main(){
vector<int> nums = {4,5,6,7,0,1,2};
int target = 0;
cout<<RotatedArray(nums,0)<<endl;//4
cout<<RotatedArray(nums,10)<<endl;//-1
 return 0;
}









