#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());

        while(pq.size() > 1){
        int stone1 = pq.top();
        pq.pop();
        int stone2 = pq.top();
        pq.pop();
        int remain = stone1 - stone2;
        pq.push(remain);
        }
        return pq.top();
    }
int main(){
vector<int> stones = {2,7,4,1,8,1};
cout<<lastStoneWeight(stones)<<endl;
return 0;
}