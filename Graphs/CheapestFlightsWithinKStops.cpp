#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
    class Info{
    public:
    int u;
    int cost;
    int stops;
    Info(int u,int cost,int stops){
        this->u = u;
        this->cost = cost;
        this->stops = stops;
    }
    };
    int findCheapestPrice(int v, vector<vector<int>>& flights, int src, int dst, int k) {
      queue<Info>q;
      vector<int> dist(v,INT_MAX);
      dist[src] = 0;
      q.push(Info(src,0,-1));

      while(!q.empty()){
        Info Curr = q.front();
        q.pop();
        for(int i=0;i<flights.size();i++){
            if(flights[i][0] == Curr.u){
            int v = flights[i][1];
            int wt = flights[i][2];
            if(dist[v] > Curr.cost + wt && Curr.stops+1 <= k){
                dist[v] = Curr.cost + wt;
                q.push(Info(v,dist[v],Curr.stops+1));
            }
            }
        }
      } 
      if(dist[dst] == INT_MAX){
        return -1;
      } 
      return dist[dst];
    }
int main(){
vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
int src = 0;
int dst = 3;
int k = 1;
cout<<findCheapestPrice(4,flights,src,dst,k);
return 0;
}