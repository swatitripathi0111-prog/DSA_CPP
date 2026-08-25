#include<iostream>
using namespace std;
int mod = 1000000007;
long long BinaryExpo(long long a,long long b){
  long long ans = 1;
  while(b>0){
  int LastDig = b&1;
  if(LastDig == 1){
    ans = (ans*a)%mod;
  }
  a = (a*a)%mod;
  b = b>>1;
  }
  return ans;
}
int CountGoodNum(int n){
return BinaryExpo(5,(n+1)/2)*BinaryExpo(4,n/2);
}
int main(){
cout<<CountGoodNum(4)<<endl;
 return 0;
}