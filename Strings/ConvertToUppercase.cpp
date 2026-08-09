#include<iostream>
#include<string>
using namespace std;
void ConvertToUppercase(string &str){
    int n = str.size();
    for(int i=0;i<n;i++){
    char ch = str[i];
    if(ch >= 'A' && ch <= 'Z'){
        continue;
    }else{
        str[i] = ch-'a'+'A';
    }
    }
}
int main(){
string str = "ApPle";
ConvertToUppercase(str);
cout<<str<<endl;
return 0;
}