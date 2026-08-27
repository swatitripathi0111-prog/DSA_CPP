#include<iostream>
#include<vector>
#include<climits>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    if(N1>N2){
    return findMedianSortedArrays(nums2,nums1);
    }
    int low = 0;
    int high = N1;
    while(low <= high){
    int mid1 = (low+high)/2;
    int mid2 = (N1+N2+1)/2-mid1;

    double L1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];
    double R1 = (mid1 == N1) ? INT_MAX : nums1[mid1];
    double L2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
    double R2 = (mid2 == N2) ? INT_MAX : nums2[mid2];

    if(L1 <= R2 && L2 <= R1){
      if((N1+N2)%2 == 0){
        return (double)(max(L1,L2)+min(R1,R2))/2;
      }else{
        return (double)(max(L1,L2));
      }
    }else if(L1 > R2){
        high = mid1-1;
    }else{
        low = mid1+1;
    }
    }
    return 0;
}
int main(){
vector<int> nums1 = {1,2};
vector<int> nums2 = {3,4};
cout<<"Median = "<<findMedianSortedArrays(nums1,nums2);//Output: 2.50000
return 0;
}