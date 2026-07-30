#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool DuplicateNum(vector<int> nums){
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
     if(nums[i] == nums[i+1]){
        return true;
     }
    }
    return false;
}
int main(){
vector<int> nums1 = {1,1,1,3,3,4,3,2,4,2};
vector<int> nums2 = {1,2,3,4};
cout<<DuplicateNum(nums1)<<endl;//1
cout<<DuplicateNum(nums2)<<endl;//0
 return 0;
}