#include<iostream>
#include<vector>
using namespace std;
int MajorityElement(vector<int> nums){
    int n = nums.size();
    int freq = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
     if(freq == 0){
        ans = nums[i];
     }
     if(ans == nums[i]){
        freq++;
     }else{
        freq--;
     }
    }
    return ans;
}
int main(){
vector<int> nums = {3,2,3};
cout<<"Majority Element = "<<MajorityElement(nums);
 return 0;
}