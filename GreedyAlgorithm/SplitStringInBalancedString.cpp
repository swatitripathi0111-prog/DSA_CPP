#include<iostream>
#include<string>
using namespace std;
int balanceStringSplit(string s){
    int n = s.size();
    int count = 0;
    int balance = 0;
    for(int i=0;i<n;i++){
     if(s[i] == 'R'){
        balance++;
     }else if(s[i] == 'L'){
       balance--;
    }
    if(balance == 0){
    count++;
    }
}
return count;
}
int main(){
string s = "RLRRLLRLRL";
cout<<"Count of Balanced String = "<<balanceStringSplit(s)<<endl;
return 0;
}