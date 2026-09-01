#include<iostream>
#include<string>
using namespace std;
void FindPermutation(string str,string ans){
 int n = str.size();
 if(n == 0){
  cout<<ans<<endl;
  return;
 }
 for(int i=0;i<n;i++){
  char ch = str[i];
  string nextstr = str.substr(0,i) + str.substr(i+1,n-i-1);
   FindPermutation(nextstr,ans+ch);
 }
}
int main(){
string str = "abc";
string ans = "";
FindPermutation(str,ans);
 return 0;
}