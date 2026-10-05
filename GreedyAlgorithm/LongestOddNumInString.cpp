#include<iostream>
#include<vector>
using namespace std;
string largestOddNumber(string num){
    int n = num.size();
    for(int i=n-1;i>=0;i--){
        int number = num[i]-'0';
        if(number%2 != 0){
            return num.substr(0,i+1);
        }
    }
    return "";
}
int main(){
string num = "4682376";
cout <<largestOddNumber(num)<<endl;
return 0;
}