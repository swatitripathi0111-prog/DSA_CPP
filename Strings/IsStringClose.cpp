#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isClose(string str1,string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    int freq1[26] = {0};
    for(int i=0;i<str1.length();i++){
        int idx1 = str1[i]-'a';
        freq1[idx1]++;
    }
    int freq2[26] = {0};
    for(int i=0;i<str2.length();i++){
        int idx2 = str2[i]-'a';
        freq2[idx2]++;
    }
    for(int i=0;i<26;i++){
     if((freq1[i]>0 && freq2[i] == 0) || (freq1[i] == 0 && freq2[i] > 0)){
        return false;
     }
    }
    sort(freq1,freq1+26);
    sort(freq2,freq2+26);

    for(int i=0;i<26;i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
  return true;
}
int main(){
string str1 = "abc";
string str2 = "bca";
cout<<isClose(str1,str2);
 return 0;
}