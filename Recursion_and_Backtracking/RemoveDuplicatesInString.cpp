#include<iostream>
#include<string>
using namespace std;
void RemoveDuplicates(string str,string ans,int i,int map[26]){
int n = str.size();
 if(i == n){
cout<<ans<<" ";
return;
 }
 int MapIdx = (int)(str[i]-'a');
 if(map[MapIdx]){//duplicate
  RemoveDuplicates(str,ans,i+1,map);
 }else{//non duplicate
  map[MapIdx] = true;
  RemoveDuplicates(str,ans+str[i],i+1,map);
 }
}
int main(){
string str = "aaabbb";
string ans = " ";
int map[26] = {false};
RemoveDuplicates(str,ans,0,map);
 return 0;
}