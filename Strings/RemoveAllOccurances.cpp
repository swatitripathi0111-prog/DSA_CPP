#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std; 
string removeOccurrences(string s, string part){
  stack<char> st;
  int k = part.size();

  for(int i=0;i<s.size();i++){
     if(s[i] == part[k-1]){
       st.push(s[i]);
       string word = "";
       while(!st.empty() && word.size() != k){
        word += st.top();
        st.pop();
       }
       reverse(word.begin(),word.end());

       if(word != part){
        int j=0;
        while(j != word.size()){
            st.push(word[j]);
            j++;
        }
       }
     }else{
        st.push(s[i]);
     }
  }
  string ans = "";
  while(!st.empty()){
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
int main(){
string s = "daabcbaabcbc";
string part = "abc"; //"dab"
cout<<removeOccurrences(s,part)<<endl;
 return 0;
} 