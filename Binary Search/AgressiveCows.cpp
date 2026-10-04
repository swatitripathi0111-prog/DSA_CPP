#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isValid(vector<int> &arr,int N,int C,int minAllowedDist){
      int cows = 1,lastStallPos = arr[0];

      for(int i=1;i<N;i++){
        if(arr[i]-lastStallPos >=  minAllowedDist){
            cows++;
            lastStallPos = arr[i];
        }
        if(cows == C){
         return true;
        }
      }
      return false;
    }
	int AggressiveCows(vector<int>& arr, int N,int C){
    sort(arr.begin(),arr.end());
    int st = 1;
    int end = arr[N-1]-arr[0];
    int ans = -1;
     while(st <= end){
        int mid = (st+end)/2;
        if(isValid(arr,N,C,mid)){
            ans = mid;
            st = mid+1;
        }else{
            end = mid-1;
        }
     }
     return ans;
    }
int main(){
vector<int> arr = {1,2,8,4,9};
int N= arr.size();
int C = 3;
cout<<AggressiveCows(arr,N,C)<<endl;
 return 0;
}