#include<iostream>
#include<vector>
using namespace std;
vector<int> PairSum(vector<int> arr,int target){
    int n = arr.size();
    vector<int> ans;
    int st = 0;
    int end = n-1;
    while(st < end){
    int sum = arr[st]+arr[end];
    if(sum == target){
    ans.push_back(st);
    ans.push_back(end);
    return ans;
    }else if(sum > target){
     end--;
    }else{
        st++;
    }
}
 return ans;
}
int main(){
vector<int> arr = {2,7,11,15};
vector<int> ans = PairSum(arr,9);
cout<<ans[0]<<","<<ans[1]<<endl;
 return 0;
}