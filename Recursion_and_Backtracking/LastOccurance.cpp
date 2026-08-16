#include<iostream>
#include<vector>
using namespace std;
int LastOccurance(vector<int> nums,int target,int i){
    if(i == nums.size()){
        return -1;
    }
    int IdxFound = LastOccurance(nums,target,i+1);
    if(IdxFound == -1 && nums[i] == target){
        return i;
    }
    return IdxFound;
}
int main(){
vector<int> nums = {1,2,3,3,3,4};
cout<<LastOccurance(nums,3,0);
 return 0;
} 