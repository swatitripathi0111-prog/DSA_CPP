#include<iostream>
#include<string>
using namespace std;
bool IsPallindrome(string str){
     int n = str.size();
     int st = 0;
     int end = n-1;
     while(st<end){
        if(str[st] != str[end]){
            return false;
        }
        st++;
        end--;
     }
     return true;
}
int main(){
string str1 = "apple";
string  str2 = "racecar";
cout<<IsPallindrome(str1)<<endl;//0
cout<<IsPallindrome(str2)<<endl;//1
return 0;
}