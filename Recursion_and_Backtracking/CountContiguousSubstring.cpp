#include<iostream>
#include<string>
using namespace std;
int CountContiguousSubstring(string str,int st,int end,int count){
int n = str.size();
if(st == n){
return count;
}
if(end == n){
return CountContiguousSubstring(str,st+1,st+1,count);
}
if(str[st] == str[end]){
count++;
}
return CountContiguousSubstring(str,st,end+1,count);
}
int main(){
string str = "abcab";
cout<<CountContiguousSubstring(str,0,0,0);
 return 0;
}