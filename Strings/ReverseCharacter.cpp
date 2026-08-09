#include<iostream>
#include<string>
using namespace std;
void ReverseChar(string &str){
 int n = str.size();
 int st = 0;
 int end = n-1;
 while(st<end){
 swap(str[st],str[end]);
 st++;
 end--;
 }
}
int main(){
string str = "swati";
ReverseChar(str);
cout<<str<<endl;
return 0;
}