#include<iostream>
#include<string>
using namespace std;
void BinaryStringProblem(int n,int LastPlace,string ans){
if(n == 0){
 cout<<ans<<endl;
 return;
}
if(LastPlace != 1){
   BinaryStringProblem(n-1,0,ans+'0');
   BinaryStringProblem(n-1,1,ans+'1');
}else{
   BinaryStringProblem(n-1,0, ans+'0');
}
}
int main(){
string ans = "";
BinaryStringProblem(3,0,ans); 
 return 0;
}