#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> MergeOverlappingIntervals(vector<vector<int>> intervals){
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin(),intervals.end());
    int CurrEndTime = intervals[0][1];
    int StartTime = intervals[0][0];

    for(int i=1;i<n;i++){
     if(intervals[i][0] <= CurrEndTime){
        if(intervals[i][1] >= CurrEndTime){
         CurrEndTime = intervals[i][1];
        }
     }else{
        ans.push_back({StartTime,CurrEndTime});
        CurrEndTime = intervals[i][1];
        StartTime = intervals[i][0];
     }
    }
    ans.push_back({StartTime,CurrEndTime});   
    return ans;
}
int main(){
vector<vector<int>> intervals = {{1,3},
                                  {2,6},
                                 {8,10},
                                  {15,18}};
vector<vector<int>> ans =  MergeOverlappingIntervals(intervals);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
     cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
} 