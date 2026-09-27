#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int MaxActivity(vector<int> start,vector<int> end){
    cout<<"selecting A0"<<endl;
    int count = 1;
    int CurrEndTime = end[0];
    for(int i=1;i<start.size();i++){
        if(start[i] >=  CurrEndTime){//non - overlapping
        cout<<"selecting A"<<i<<endl;
         count++;
         CurrEndTime = end[i];
        }
    }
    return count;
}
int main(){
vector<int> start = {1,3,0,5,8,5};
vector<int> end = {2,4,6,7,9,9};
cout<<MaxActivity(start,end)<<endl;
return 0;
}