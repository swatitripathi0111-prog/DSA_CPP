#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<vector<int>> s;
void getAllcombination(vector<int> &arr,int idx,int tar,vector<vector<int>> &ans,vector<int> &combin){
    if(idx == arr.size() || tar < 0){
        return;
    }
    if(tar == 0){
     if(s.find(combin) == s.end()){
        ans.push_back(combin);
        s.insert(combin);
     }
     return;
    }
    combin.push_back(arr[idx]);
    getAllcombination(arr,idx+1,tar-arr[idx],ans,combin);
    getAllcombination(arr,idx,tar-arr[idx],ans,combin);
    combin.pop_back();
    getAllcombination(arr,idx+1,tar,ans,combin);
}
vector<vector<int>> combinationSum(vector<int>&arr,int target){
    vector<vector<int>> ans;
    vector<int> combin;
    getAllcombination(arr,0,target,ans,combin);
    return ans;
}
int main(){
vector<int> nums = {2,3,5};
vector<vector<int>> ans = combinationSum(nums,8);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}