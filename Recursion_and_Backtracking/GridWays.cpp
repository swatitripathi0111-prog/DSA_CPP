#include<iostream>
#include<vector>
using namespace std;
int GridWays(int r,int c,int n,int m, string ans){
    if(r == n-1 && c == m-1){
      cout<<ans<<endl;
      return 1;
    }
    if(r >= n || c >= m){
        return 0;
    }
    int val1 = GridWays(r,c+1,n,m,ans+"R");
    int val2 = GridWays(r+1,c,n,m,ans+"D");
    return val1 + val2;
}
int main(){
int n = 3;//rows
int m = 3;//colunm
string ans = "";
cout<<"Number of Ways = "<<GridWays(0,0,n,m,ans);
 return 0;
}