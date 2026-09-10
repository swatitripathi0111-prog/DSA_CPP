#include<iostream>
#include<stack>
using namespace std;
void SortStack(stack<int> &original){
     stack<int> temp;
 
     while(!original.empty()){
     int x = original.top();
     original.pop();

     while(!temp.empty() && x < temp.top()){
        original.push(temp.top());
        temp.pop();
     }
     temp.push(x);
     }
     while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
     }
}
int main(){
stack<int> original;
original.push(3);
original.push(1);
original.push(2);
SortStack(original);
return 0;
}