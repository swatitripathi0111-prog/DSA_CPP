#include<iostream>
#include<stack>
#include<string>
using namespace std;
void PrintStack(stack<int> s){
    while(!s.empty()){
     cout<<s.top()<<" ";
     s.pop();
    }
    cout<<endl;
}
void PushAtBottom(stack<int> &s,int val){
    if(s.empty()){
    s.push(val);
    return;
    }
    int temp = s.top();
    s.pop();
    PushAtBottom(s,val);
    s.push(temp);
}
void Reverse(stack<int> &s){
    if(s.empty()){
    return;
    }
    int temp = s.top();
    s.pop();
    Reverse(s);
    PushAtBottom(s,temp);
}
int main(){
stack<int> s;
s.push(3);
s.push(2);
s.push(1);
PrintStack(s);
Reverse(s);
PrintStack(s);
return 0;
}