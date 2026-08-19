#include<iostream>
#include<vector>
#include<string>
using namespace std;
 int compress(vector<char>& chars){
 int n = chars.size();
 int st = 0;
 int end = 1;
 int count = 1;
 int idx = 1;
 while(end < n){
    if(chars[st] == chars[end]){
        count++;
    }else{
     if(count != 1){
      string s = to_string(count);
      for(char c : s){
        chars[idx++] = c;
      }
      chars[idx++] = chars[end];
      count = 1;
     }
    }
    st++;
    end++;
 }
 if(count != 1){
    string s = to_string(count);
    for(char c : s){
     chars[idx++] = c;
    }
 }
 return idx;
 }
int main(){
vector<char> chars = {'a','a','b','b','c','c','c'};
cout<<compress(chars);
 return 0;
}