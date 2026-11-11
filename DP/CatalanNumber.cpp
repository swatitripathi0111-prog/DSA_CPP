#include<iostream>
#include<vector>
using namespace std;
//using recursion
int CatalanRec(int n){
  if(n == 0 || n == 1){
    return 1;
  }
  int ans = 0;
  for(int i=0;i<n;i++){
    ans += CatalanRec(i) * CatalanRec(n-i-1);
  }
  return ans;
}
//using Memoisation
int CatalanMemo(int n,vector<int> &dp){
if(n == 0 || n == 1){
    return 1;
}
if(dp[n] != -1){
    return dp[n];
}
int ans = 0;
for(int i=0;i<n;i++){
 ans += CatalanMemo(i,dp) * CatalanMemo(n-i-1,dp);
}
return dp[n] = ans;
}
//using tabulation
int CatalanTab(int n){
vector<int> dp(n+1,0);
dp[0] = dp[1] = 1;
for(int i=2;i<=n;i++){
    for(int j=0;j<i;j++){
    dp[i] += dp[j] * dp[i-j-1];
    }
}
return dp[n];
}
int main(){
int n = 4;
cout<<CatalanRec(n)<<endl; 
vector<int> dp(n+1,-1);
for(int i=0;i<=n;i++){
cout<<CatalanMemo(i,dp)<<" ";
}
cout<<endl;
for(int i=0;i<=n;i++){
cout<<CatalanTab(i)<<" ";
}
return 0;
}