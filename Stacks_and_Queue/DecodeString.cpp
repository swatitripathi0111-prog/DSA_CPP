#include<iostream>
#include<stack>
using namespace std;
string decodeString(string s) {
    stack<int> NumStack;
    stack<string> StrStack;
    int num = 0;
    string Curr = "";

    for(char ch : s){
    if(isdigit(ch)){
    num = num*10 + (ch-'0');
    }else if(ch == '['){
      NumStack.push(num);
      StrStack.push(Curr);
      num = 0;
      Curr = "";
    }else if(ch == ']'){
       int repeat = NumStack.top();
                     NumStack.pop();
        string prev = StrStack.top();
                      StrStack.pop();
        string temp = "";
        for(int i=0;i<repeat;i++){
            temp += Curr;
        }
        Curr = prev + temp;
    }else{
        Curr += ch;
    }
    }
    return Curr;
    }
int main(){
string str = "3[a]2[bc]";
cout<<decodeString(str);
return 0;    
}