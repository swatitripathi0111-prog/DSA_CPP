#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(freq[a] == freq[b]){
                return a  > b;
            }
            return freq[a] < freq[b];
        });
        return nums;
}
int main(){
vector<int> nums = {1,1,2,2,2,3};
vector<int> ans = frequencySort(nums);
for(int i=0;i<ans.size();i++){//3,1,1,2,2,2
    cout<<ans[i]<<" ";
}
return 0;
}