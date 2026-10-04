#include<iostream>
#include<vector>
using namespace std;
    bool isValid(vector<int> &arr,int n,int k,int maxSum){
       int SubArrays = 1;
       int sum = 0;
       for(int i=0;i<n;i++){
        if(arr[i] > maxSum){
            return false;
        }
        if(sum + arr[i] <= maxSum){
            sum += arr[i];
        }else{
            SubArrays++;
            sum = arr[i];
        }
       }
      return SubArrays > k ? false : true;
    }    
    int splitArray(vector<int>& arr, int k) {
      int n = arr.size();
     if(n < k){
        return -1;
     } 
     int range = 0;
     for(int i=0;i<n;i++){
        range += arr[i];
     }
     int st = 0;
     int end = range;
     int ans = -1;
     while(st <= end){
      int mid = (st+end)/2;
      if(isValid(arr,n,k,mid)){
        ans = mid;
        end = mid-1;
      }else{
        st = mid+1;
      }
     }
     return ans;
    }
int main(){
vector<int> nums = {7,2,5,10,8};
int k = 2;
cout<<splitArray(nums,k)<<endl;
return 0;
}