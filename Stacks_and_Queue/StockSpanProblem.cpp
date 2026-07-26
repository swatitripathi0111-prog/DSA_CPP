#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void StockSpanProblem(vector<int> stock,vector<int> span){
  stack<int> s;
  s.push(0);
  span[0] = 1;

  for(int i=1;i<stock.size();i++){
    int CurrPrice = stock[i];
    while(!s.empty() && CurrPrice >= stock[s.top()]){
    s.pop();
    }
    if(s.empty()){
    span[i] = i+1;
    }else{
    int PrevHigh = s.top();
    span[i] = i-PrevHigh;
    }
    s.push(i);
  }
  for(int i=0;i<span.size();i++){
    cout<<span[i]<<" ";
  }
} 
int main(){
vector<int> stock = {100,80,60,70,60,85,100};
vector<int> span = {0,0,0,0,0,0,0};
StockSpanProblem(stock,span);
 return 0;
}