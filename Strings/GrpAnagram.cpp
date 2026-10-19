#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < strs.size(); i++) {
        string s = strs[i];
        sort(s.begin(), s.end());
        mp[s].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto it : mp) {
        ans.push_back(it.second);
    }
    return ans;
}
int main(){
vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
vector<vector<string>> ans = groupAnagrams(strs);
for(int i=0;i<ans.size();i++){//[["bat"],["nat","tan"],["ate","eat","tea"]]
  for(int j=0;j<ans[i].size();j++){
    cout<<ans[i][j]<<" ";
  }
  cout<<endl;
}
return 0;
}