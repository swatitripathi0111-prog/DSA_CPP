#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//using recursion
int MCMRec(vector<int> &arr,int i,int j){
    if(i == j){
    return 0;
    }
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
    int cost1 = MCMRec(arr,i,k);
    int cost2 = MCMRec(arr,k+1,j);
    int CurrCost = cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]);
    ans = min(ans,CurrCost);
    }
    return ans;
}
//using memoisation 
int MCMMemo(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
    if(i == j){
    return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
    int cost1 = MCMMemo(arr,i,k,dp);
    int cost2 = MCMMemo(arr,k+1,j,dp);
    int CurrCost = cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]);
    ans = min(ans,CurrCost);
    }
    return dp[i][j] = ans;
}
//using tabulation
int MCMTab(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=1;i<n;i++){
    dp[i][i] = 0;
    } 
    for(int len=2;len<n;len++){
     for(int i=1;i<=n-len;i++){
        int j = i+len-1;
        dp[i][j] = INT_MAX;
        for(int k=i;k<j;k++){
        int cost1 = dp[i][k];
        int cost2 = dp[k+1][j];
        int CurrCost = cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]);
        dp[i][j] = min(dp[i][j],CurrCost);
        }
     }
    }
    return dp[1][n-1];
}
int main(){
vector<int> arr = {1,2,3,4,3};
int n = arr.size();
cout<<"Minimum Cost1 = "<<MCMRec(arr,1,n-1)<<endl;
vector<vector<int>> dp(n,vector<int>(n,-1)); 
cout<<"Minimum Cost2 = "<<MCMMemo(arr,1,n-1,dp)<<endl;
cout<<"Minimum Cost3 = "<<MCMTab(arr)<<endl;
return 0;
}