#include<iostream>
#include<vector>
using namespace std;
void MergeTwoArraysWithoutExtraSpace(vector<int> nums1,int m,vector<int> nums2,int n){
    int i = m-1;//pointing to nums1
    int j = n-1;//pointing to nums2
    int end = m+n-1;
    if(m == 0){
        for(int i=0;i<n;i++){
            nums1[i] = nums2[i];
        }
        return;
    }
    while(i >= 0 && j >= 0){
     if(nums1[i] <= nums2[j]){
        nums1[end] = nums2[j];
        j--;
        end--;
     }else{
        nums1[end] = nums1[i];
        i--;
        end--;
     }
     while(j >= 0){
     nums1[end] = nums2[j];
     j--;
     end--;
     }
    }
    //printing nums1
    for(int i=0;i<n+m;i++){
    cout<<nums1[i]<<" ";
    }
}
int main(){
vector<int> nums1 = {1,2,3,0,0,0};
vector<int> nums2 = {4,5,6};
MergeTwoArraysWithoutExtraSpace(nums1,3,nums2,3);
 return 0;
}