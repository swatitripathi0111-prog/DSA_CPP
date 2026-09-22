#include<iostream>
using namespace std;
class Queue{
    int capacity;
    int *arr;
    int CurrSize;
    int f,r;
public:
   Queue(int capacity){
    this->capacity = capacity;
    arr = new int[capacity];
    CurrSize = 0;
    f = 0;
    r = -1;
   }
   void push(int data){
   if(CurrSize == capacity){
    cout<<"Queue is Full"<<endl;
    return;
   }
   r = (r+1)%capacity;
   arr[r] = data;
   CurrSize++;
   }
   void pop(){
   if(isEmpty()){
    cout<<"Queue is sempty\n";
    return;
   }
   f = (f+1)%capacity;
   CurrSize--;
   }
   int front(){
   if(isEmpty()){
    cout<<"Queue is sempty\n";
    return -1;
   }
   return arr[f];
   }
   bool isEmpty(){
    return CurrSize == 0;
   }
};
int main(){
Queue q(4);
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);
cout<<q.front()<<endl;
q.pop();
cout<<q.front()<<endl;
q.push(5);
cout<<q.front()<<endl;
return 0;
}