#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
string simplifyPath(string path){
    stack<string> s;
    string temp = "";

    for(char ch : path){
        if(ch != '/'){
             temp += ch;
        }else{
            if(temp == ".."){
              if(!s.empty()){
                s.pop();
              }
              }else if(temp == "." || temp == ""){

              }else{
                s.push(temp);
              }
              temp = "";
            }
        }
        if(temp == ".."){
            if(!s.empty()){
                s.pop();
            }
            }else if(temp == "." || temp == ""){

            }else{
            s.push(temp);
            }
            vector<string> dics;
            string str = "";
            while(!s.empty()){
             dics.push_back(s.top());
             s.pop();
            }
            reverse(dics.begin(),dics.end());
            for(int i=0;i<dics.size();i++){
                str += "/";
                str += dics[i];
            }
            if(str.empty()){
              return "/";
            }else{
                return str;
            }
}
int main(){
string path = "/home/user/Documents/../Pictures";
cout<<simplifyPath(path);//output : "/home/user/Pictures"
 return 0;
}