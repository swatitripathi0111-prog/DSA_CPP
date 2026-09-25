#include<iostream>
#include<queue>
using namespace std;
void Interleave(queue<int>&original){
  int n = original.size();
  queue<int> first;
  for(int i=0;i<n/2;i++){
    first.push(original.front());
    original.pop();
  }
  while(!first.empty()){
    original.push(first.front());
    first.pop();
    original.push(original.front());
    original.pop();
  }
}
int main(){
queue<int> original;
for(int i=1;i<=10;i++){
    original.push(i);
}
Interleave(original);
while(!original.empty()){
    cout<<original.front()<<" ";
    original.pop();
}
return 0;
}