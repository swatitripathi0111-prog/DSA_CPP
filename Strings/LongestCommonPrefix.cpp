#include<iostream>
#include<string>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs){
 if(strs.size() == 1){
    return strs[0];
 }
 string s1 = strs[0];
 string ans = "";
 for(int i=0;i<strs.size()-1;i++){
   string s2 = strs[i+1];
   string temp = "";
   for(int j=0,k=0;j<s2.size() && k<s1.size();j++,k++){
    if(s1[k] == s2[j]){
     char ch = s1[k];
     temp += ch;
    }else{
        break;
    }
   }
   ans = temp;
   s1 = ans;
 }
 return ans;
}
int main(){
vector<string> strs = {"flower","flow","flight"};
cout<<longestCommonPrefix(strs);
 return 0;
}