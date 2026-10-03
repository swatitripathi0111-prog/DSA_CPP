#include<iostream>
#include<vector>
#include<climits>
using namespace std;
bool isValid(vector<int> &arr,int n,int m,int maxAllowedTime){
      int Painters = 1,time=0;

      for(int i=0;i<n;i++){
        if(arr[i] >= maxAllowedTime){
            return false;
        }
        if(time + arr[i] <= maxAllowedTime){
            time += arr[i];
        }else{
            Painters++;
            time = arr[i];
        }
      }
      return Painters > m ? false : true;
    }
	int PainterPartition(vector<int>& arr, int k) {
    int n = arr.size();
     if(k > n){
        return -1;
     }
     int sum = 0,MaxVal=INT_MIN;
     for(int i=0;i<n;i++){
        sum += arr[i];
        MaxVal = max(MaxVal,arr[i]);
     }
     int ans = -1;
     int st = MaxVal;
     int end = sum;

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
vector<int> arr = {40,30,10,20};
int n = arr.size();
int m = 2;
cout<<"Minimum possible answer = "<<PainterPartition(arr,m)<<endl;
 return 0;
}