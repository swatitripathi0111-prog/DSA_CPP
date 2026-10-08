#include<iostream>
#include<string>
using namespace std;
string getSmallestString(int n, int k) {
    string ans(n,'a');
    k = k-n;
    for(int i=n-1;i>=0;i--){
      if(k > 25){
        ans[i] = 'z';
        k = k-25;
      }else{
        ans[i] += k;
        break; 
      }
    }
    return ans;
}
int main(){
int n = 3,k = 27;
cout<<"ans = "<<getSmallestString(n,k)<<endl;
return 0;
}