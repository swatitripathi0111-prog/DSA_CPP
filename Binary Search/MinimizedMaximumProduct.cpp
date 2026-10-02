#include<iostream>
#include<vector>
using namespace std;
    bool isValid(vector<int> &quantities,int n,int m,int MaxProductAllowedPerStore){
       int stores = 0;
       for(int i=0;i<m;i++){
         stores += quantities[i]/MaxProductAllowedPerStore;
         if(quantities[i]%MaxProductAllowedPerStore != 0){
            stores++;
         }
       }
       if(stores <= n){
        return true;
       }
       return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
      int m = quantities.size();
      int st = 1;
      int end = 0;
      for(int i=0;i<m;i++){
        end = max(end,quantities[i]);
      }
      int ans = -1;
      while(st <= end){
        int mid = (st+end)/2;
        if(isValid(quantities,n,m,mid)){
            ans = mid;
            end = mid-1;  
        }else{
            st = mid+1;
        }
      }
      return ans;
    }
int main(){
vector<int> quantities = {11,6};
cout<<minimizedMaximum(6,quantities);
return 0;
}