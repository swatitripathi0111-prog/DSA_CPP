#include<iostream>
#include<vector>
using namespace std;
int MaxWater(vector<int> heights){
    int n = heights.size();
    int LeftIdx = 0;
    int RightIdx = n-1;
    int MaxWater = 0;

    while(LeftIdx < RightIdx){
    int width = RightIdx-LeftIdx;
    int CurrWater = min(heights[LeftIdx],heights[RightIdx])*width;
    MaxWater = max(CurrWater,MaxWater);
    if(heights[RightIdx] < heights[LeftIdx]){
        RightIdx--;
    }else{
        LeftIdx++;
    }
    }
 return MaxWater;
}
int main(){
vector<int> height = {1,8,6,2,5,4,8,3,7};
cout<<MaxWater(height);
 return 0;
}