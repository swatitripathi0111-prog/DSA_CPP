#include<iostream>
#include<vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = 1;
    for(int i=1;i<n;i++){
    ans[i] = ans[i-1]*nums[i-1];
    }
   int RightProduct = 1;
   for(int i=n-1;i>=1;i--){
    RightProduct = nums[i] *RightProduct;
    ans[i-1] = RightProduct * ans[i-1];
}
 return ans;
}
int main(){
vector<int> nums = {-1,1,0,-3,3};
vector<int> ans = productExceptSelf(nums);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
 return 0;
}
