#include<iostream>
#include<vector>
using namespace std;
int FibonacciMemo(int n,vector<int> &fib){
  if(n == 0 || n == 1){
    return n;
  }
  if(fib[n] != -1){
    return fib[n];
  }
  fib[n] = FibonacciMemo(n-1,fib)+FibonacciMemo(n-2,fib);
  return fib[n];

}
int main(){
int n = 6;
vector<int> fib(n+1,-1);
cout<<FibonacciMemo(n,fib);
return 0;
}