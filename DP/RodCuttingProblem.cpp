#include<iostream>
#include<vector>
using namespace std;
int RodCutting(vector<int> prices,vector<int> length,int RodLength){
    int n = length.size();
    vector<vector<int>> dp(n+1,vector<int>(RodLength+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<RodLength+1;j++){
            if(length[i-1] <= j){
            dp[i][j] = max(prices[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][RodLength];
}
int main(){
vector<int> prices = {1,5,8,9,10,17,17,20};
vector<int> length = {1,2,3,4,5,6,7,8};
int RodLength = 8;
cout<<"Maximum Profit = "<<RodCutting(prices,length,RodLength)<<endl;
return 0;
}