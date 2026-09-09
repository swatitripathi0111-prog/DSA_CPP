#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Stack{
 vector<T> vec;
public:
  void push(int val){
  vec.push_back(val);
  }
  void pop(){
  if(isEmpty()){
    cout<<"Stack is empty";
    return;
  }
  vec.pop_back();
  }
  T top(){
  int LastIdx = vec.size()-1;
  return vec[LastIdx];
  }
  bool isEmpty(){
   return vec.size() == 0;
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