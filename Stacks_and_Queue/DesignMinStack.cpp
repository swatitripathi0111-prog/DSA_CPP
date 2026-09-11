#include<iostream>
#include<stack>
using namespace std;
class Stack{
public:
   stack<long long int > s;
   long long int minVal;

   void push(int val){
    if(s.empty()){
    s.push(val);
    minVal = val;
    }else{
     if(val < minVal){
      s.push((long long)2*val-minVal);
      minVal = val;
     }else{
        s.push(val);
     }
    }
   }
   void pop(){
    if(s.top() < minVal){
    minVal = 2*minVal-s.top();
    }
    s.pop(); 
   }
   int top(){
    if(s.top() < minVal){
        return minVal;
    }
    s.top();
   }
   int getMin(){
    return minVal;
   }
};
int main(){
 return 0;
}