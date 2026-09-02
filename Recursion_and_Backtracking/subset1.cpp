#include<iostream>
#include<vector>
using namespace std;
void CalSubset(vector<int>nums,vector<int>ans,int i,vector<vector<int>> &finalAns){
    if(i == nums.size()){
    finalAns.push_back(ans);
    return;
    }
    ans.push_back(nums[i]);
    CalSubset(nums,ans,i+1,finalAns);
    ans.pop_back();
    CalSubset(nums,ans,i+1,finalAns);
}
vector<vector<int>> subset(vector<int> nums){
    vector<vector<int>> finalans;
    vector<int> ans;
    CalSubset(nums,ans,0,finalans);
    return finalans;
}
int main(){
vector<int> nums = {1,2,3};
vector<vector<int>> finalans = subset(nums);
for(int i=0;i<finalans.size();i++){
    for(int j=0;j<finalans[i].size();j++){
     cout<<finalans[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}