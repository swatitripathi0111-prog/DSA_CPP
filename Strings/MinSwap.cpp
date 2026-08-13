#include<iostream>
#include<string>
using namespace std;
bool MinSwap(string str1,string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    int first = -1;
    int second = -1;
    for(int i=0;i<str1.length();i++){
      if(str1[i] != str2[i]){
        if(first == -1){
        first = i;
        }else if(second == -1){
            second = i;
        }else{
            return false;
        }
    }
}
if(first == -1) return true;
if(second == -1) return false;
if(str1[first] == str2[second] && str1[second] == str2[first]){
    return true;
}
return false;
}
int main(){
string s1 = "bank";
string s2 = "kanb";
cout<<MinSwap(s1,s2);
 return 0;
}