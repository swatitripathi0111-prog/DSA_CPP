#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int> &arr,int n,int m,int maxAllowedLength){
      int Painters = 1,length=0;
      for(int i=0;i<n;i++){
        if(arr[i] > maxAllowedLength){
          return false;
        }
        if(length + arr[i] <= maxAllowedLength){
            length += arr[i];
        }else{
            Painters++;
            length = arr[i];
        }
      }
      return Painters > m ? false : true;
    }
	int PainterPartition(vector<int>& arr, int k) {
        int n = arr.size();
     if(k > n){
        return -1;
     }
     int sum = 0;
     for(int i=0;i<n;i++){
        sum += arr[i];
     }
     int ans = -1;
     int st = 0;
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
vector<int> arr = {2,1,4,3};
int n = arr.size();
int m = 2;
cout<<"Minimum possible answer = "<<PainterPartition(arr,m)<<endl;
 return 0;
}