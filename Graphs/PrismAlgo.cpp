#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
public:
  int v;
  list<pair<int,int>> *l;
  bool isUndir;
  Graph(int v,bool isUndir=true){
    this->v = v;
    l = new list<pair<int,int>> [v];
    this->isUndir = isUndir;
  }
  void addEdge(int u,int v,int wt){
    l[u].push_back(make_pair(v,wt));
    if(isUndir){
    l[v].push_back(make_pair(u,wt));
    }
  }
  void PrismAlgo(int src){
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   vector<bool> mst(v,false);
   pq.push(make_pair(0,src));
   int ans = 0;
   while(pq.size() > 0){
    int u = pq.top().second;
    int wt = pq.top().first;
    pq.pop();
    if(!mst[u]){
    mst[u] = true;
    ans += wt;
    list<pair<int,int>> neighbour = l[u];
    for(pair<int,int> n : neighbour){
     int v = n.first;
     int CurrWt = n.second;
     pq.push(make_pair(CurrWt,v));
    }
    }
   }
   cout<<"Final cost of MST = "<<ans<<endl;
}
};
int main(){
Graph graph(4);
graph.addEdge(0,1,10);
graph.addEdge(0,2,15);
graph.addEdge(0,3,30);
graph.addEdge(1,3,40);
graph.addEdge(2,3,50);
graph.PrismAlgo(0);
return 0;
}