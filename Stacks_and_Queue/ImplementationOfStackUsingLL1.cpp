#include<iostream>
#include<list>
using namespace std;
template<class T>
class Stack{
  list<T> LL;
public:
  void push(T val){
   LL.push_front(val);
  }
  void pop(){
  LL.pop_front();
  }
  T top(){
  return LL.front();
  }
  bool isEmpty(){
   return LL.size() == 0;
  }
};
int main(){
Stack<int> s;
s.push(3);
s.push(2);
s.push(1);

while(!s.isEmpty()){
  cout<<s.top()<<" ";
  s.pop();
}
return 0;
}