#include<iostream>
#include<vector>
using namespace std;
//using recursion
int CountWaysRec(int n){
 if(n == 0 || n == 1){
    return 1;
 }
return CountWaysRec(n-1) + CountWaysRec(n-2);
}
//using memoization
int CountWaysMemo(int n,vector<int> &dp){
    if(n == 0 || n == 1){
    return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = CountWaysMemo(n-1,dp)+CountWaysMemo(n-2,dp);
    return dp[n];
}
//using tabulation
int CountWaysTabu(int n){
 vector<int> dp(n+1,0);
 dp[0] = 1;
 dp[1] = 1;
 for(int i=2;i<=n;i++){
    dp[i] = dp[i-1] + dp[i-2];
 }
 return dp[n];
}
int main(){
int n = 5;
cout<<"Count Number of Ways using recursion = "<<CountWaysRec(n)<<endl;//8
vector<int> dp1(n+1,-1);
cout<<"Count Number of Ways using Memoisation = "<<CountWaysMemo(n,dp1)<<endl;//8
cout<<"Count Number of Ways using Tabulation = "<<CountWaysTabu(n)<<endl;//8
return 0;
}