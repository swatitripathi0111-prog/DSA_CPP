#include<iostream>
#include<climits>
using namespace std;
int MaxSumSubarray(int *arr,int n){
   int MaxSum = INT_MIN;
   int Currsum = 0;
   for(int i=0;i<n;i++){
    Currsum = Currsum + arr[i];
    MaxSum = max(MaxSum,Currsum);
    if(Currsum < 0){
    Currsum = 0;
    }
   }
   return MaxSum;
}
int main(){
int arr[] = {2,-3,6,-5,4,2};
cout<<"Maximum sum of Subarray = "<<MaxSumSubarray(arr,6)<<endl;
 return 0;
}