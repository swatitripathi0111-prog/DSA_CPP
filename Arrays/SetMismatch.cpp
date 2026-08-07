#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> SetMismatch(vector<int> nums){
   int n = nums.size();
   sort(nums.begin(),nums.end());
   vector<int> ans;
   int DuplicateNum = -1;
   int MissingNum = -1;
   //calculating Dupliacate Number
   for(int i=0;i<n-1;i++){
    if(nums[i] == nums[i+1]){
    DuplicateNum = nums[i];
    ans.push_back(DuplicateNum);
    break;
    }
   }
   //calculating Missing Number
   int ExpectedSum = (n*(n+1))/2;
   int CurrSum = 0;
   for(int i=0;i<n;i++){
    CurrSum += nums[i];
   }
   MissingNum = (ExpectedSum - CurrSum) + DuplicateNum;
   ans.push_back(MissingNum);
   return ans;
}
int main(){
vector<int> nums = {1,2,2,4};
vector<int> ans = SetMismatch(nums);
cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl;
 return 0;
}