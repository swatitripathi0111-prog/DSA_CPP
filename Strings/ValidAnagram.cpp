#include<iostream>
#include<string>
using namespace std;
bool IsvalidAnagram(string str1,string str2){
  if(str1.length() != str2.length()){
    cout<<"Not valid Anagram"<<endl;
    return false;
  }
  int count[26] = {0};
  for(int i=0;i<str1.length();i++){
    int idx = str1[i]-'a';
    count[idx]++;
  }
  for(int i=0;i<str2.length();i++){
    int idx = str2[i] -'a';
    if(count[idx] == 0){
    cout<<"Not valid Anagram"<<endl;
    return false;
    }
    count[idx]--;
  }
cout<<"Valid Anagram"<<endl;
return true;
}
int main(){
string str1 = "anagram";
string str2 = "nagaram";
cout<<IsvalidAnagram(str1,str2)<<endl;
return 0;
}