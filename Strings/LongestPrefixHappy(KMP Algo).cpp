#include<iostream>
#include<vector>
#include<string>
using namespace std;
string longestPrefix(string s) {
     int n = s.size();
     vector<int> lps(n,0);
     int pre = 0;
     int suf = 1;
     while(suf < n){
      if(s[pre] == s[suf]){
        lps[suf] = pre+1;
        suf++;
        pre++;
      }else{
        if(pre == 0){
         lps[suf] = 0;
         suf++;
        }else{
        pre = lps[pre-1];
        }
      }
     }
     return s.substr(0,lps[n-1]);
}
int main(){
string s = "ababab";
cout<<longestPrefix(s);
 return 0;
}