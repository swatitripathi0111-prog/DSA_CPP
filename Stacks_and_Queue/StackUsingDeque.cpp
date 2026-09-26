#include<iostream>
#include<deque>
using namespace std;
class Stack{
 deque<int> deq;
public:
  void push(int data){
 deq.push_front(data);
  }
  void pop(){
   deq.pop_front();
  }
  int top(){
  return deq.front();
  }
  bool empty(){
    return deq.empty();
  }
  
};
int main(){
Stack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
}
return 0;
}