#include<iostream>
#include<vector>
using namespace std;
int canCompleteCircuit(vector<int> &gas,vector<int> &cost){
    int TotGas = 0;
    int TotCost = 0;
    int start = 0;
    int CurrGas = 0;

    for(int i=0;i<gas.size();i++){
        TotCost += cost[i];
        TotGas += gas[i];
        CurrGas += (gas[i]-cost[i]);
        if(CurrGas < 0){
            start = i+1;
            CurrGas = 0;
        }
    }
    return TotGas < TotCost ? -1 : start;
}
int main(){
vector<int> gas = {1,2,3,4,5};
vector<int> cost = {3,4,5,1,2};
cout<<canCompleteCircuit(gas,cost)<<endl;
return 0;
}