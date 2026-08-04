#include<iostream>
#include<vector>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>> grid){
    int n = grid.size();
    vector<int> ans;
    int freq[2501] = {0};
    int Repeated = -1;
    int Missing = -1;
    for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
      freq[grid[i][j]]++;  
        }
    }
    for(int i=1;i<=n*n;i++){
     if(freq[i] > 1){
     Repeated = i;
     }
     if(freq[i] == 0){
     Missing = i;
     }
    }
    ans.push_back(Repeated);
    ans.push_back(Missing);
    return ans;
}
int main(){
vector<vector<int>> grid = {{9,1,7},
                            {8,9,2},
                             {3,4,6}};
vector<int>ans = findMissingAndRepeatedValues(grid);

//print ans
for(int i=0;i<2;i++){
cout<<ans[i]<<" ";
}
 return 0;
}