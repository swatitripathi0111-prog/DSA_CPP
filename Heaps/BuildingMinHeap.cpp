#include<iostream>
#include<vector>
using namespace std;
class Heap{
  vector<int> vec;
public:
  void push(int val){
  vec.push_back(val);
   //fix heap
   int x = vec.size()-1;
   int ParI = (x-1)/2;
   while(ParI >= 0 && vec[x] < vec[ParI]){
    swap(vec[ParI],vec[x]);
    x = ParI;
    ParI = (x-1)/2;
   }
  }
  void Heapify(int i){
if(i >= vec.size()){
    return;
}
  int MaxIdx = i;
  int l = 2*i+1;
  int r = 2*i+2;
  if(l < vec.size() && vec[l] < vec[MaxIdx]){
    MaxIdx = l;
  }
  if(r < vec.size() && vec[r] < vec[MaxIdx]){
    MaxIdx = r;
  }
  swap(vec[i],vec[MaxIdx]);
  if(MaxIdx != i){
    Heapify(MaxIdx);
  }
 }
  void pop(){
  //step-1
  swap(vec[0],vec[vec.size()-1]);
  //step-2
  vec.pop_back();
  //step-3
  Heapify(0);
  }
  int top(){
  return vec[0];
  }
  bool empty(){
  return vec.size() == 0;
  }
};
int main(){
Heap heap;
heap.push(9);
heap.push(8);
heap.push(5);
heap.push(4);
heap.push(2);
heap.push(1);
while(!heap.empty()){
cout<<"Top = "<<heap.top()<<endl;
heap.pop();
}
return 0;
}