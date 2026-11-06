#include<iostream>
#include<vector>
using namespace std;
bool TargetSum(vector<int> &nums,int target){
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(nums[i-1] <= j){
             dp[i][j] = max(nums[i-1]+dp[i-1][j-nums[i-1]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target] == target;
}
int main(){
vector<int> nums = {4,2,7,1,3};
int target = 7;
cout<<TargetSum(nums,target);
return 0;
}