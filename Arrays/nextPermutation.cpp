#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void NextPermutation(vector<int> &nums){
   int n = nums.size();
   int temp = 0;
   int tempIdx = -1;
   int right = n-1;
   int left = n-2;
   bool yes = false;
   while(left >= 0){
    if(nums[left] < nums[right]){
        temp = nums[left];
        tempIdx = left;
        yes = true;
        break;
    }
    right--;
    left--;
   }
   int MinNum = INT_MAX;
   int MinIdx = -1;
   if(yes == true){
   for(int i=right;i<n;i++){
    if(temp < nums[i]){
    MinNum = min(MinNum,nums[i]);
    MinIdx = i;
    }
   }
   swap(nums[tempIdx],nums[MinIdx]);
   }
   int st = right;
   int end = n-1;
   while(st<end){
   swap(nums[st],nums[end]);
    st++;
    end--;
   }
}
int main(){
vector<int> nums = {2,4,3,1};
NextPermutation(nums);
for(int i=0;i<nums.size();i++){
    cout<<nums[i]<<" ";
}
 return 0;
}
