#include<iostream>
#include<vector>
using namespace std;
void SortColor(vector<int> &nums){
    int n = nums.size();
    int mid = 0,low = 0,high = n-1;
    while(mid <= high){
    if(nums[mid] == 0){
      swap(nums[mid],nums[low]);
      mid++;
      low++;
    }else if(nums[mid] == 1){
     mid++;
    }else{
     swap(nums[mid],nums[high]);
     high--;
    }
    }
}
int main(){
vector<int> nums = {2,0,2,1,1,0};
SortColor(nums);
for(int i=0;i<nums.size();i++){
 cout<<nums[i]<<" ";
}
 return 0;
}