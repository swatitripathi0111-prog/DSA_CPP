#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minCostConnectPoints(vector<vector<int>>& points) {
    int v = points.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int src = 0;
   vector<bool> mst(v,false);
   pq.push(make_pair(0,src));
   int minCost = 0;
   while(pq.size() > 0){
    int u = pq.top().second;
    int cost = pq.top().first;
    pq.pop();
    if(!mst[u]){
    mst[u] = true;
    minCost += cost;
    for(int V=0;V<v;V++){
        if(u != V){
            int wt = abs(points[u][0]-points[V][0])+ abs(points[u][1]-points[V][1]);
            pq.push(make_pair(wt,V));
        }
    }
    }
   }
   return minCost;
}
int main(){
vector<vector<int>> points = {{3,12},{-2,5},{-4,1}};
cout<<"Min Cost = "<<minCostConnectPoints(points);
return 0;
}