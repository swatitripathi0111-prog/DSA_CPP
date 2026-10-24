#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
   int v;
   list<int> *l;
public:
  Graph(int v){
   this->v = v;
   l = new list<int>[v];
  }
  void AddEdge(int u,int v){
  l[u].push_back(v);
  l[v].push_back(u);
  }
  bool undirCycleHelper(int src,int par,vector<bool> &vis){
    vis[src] = true;
    list<int> neighbours = l[src];
    for(int v : neighbours){
        if(!vis[v]){
         if(undirCycleHelper(v,src,vis)){
            return true;
         }
         }else{
            if(v != par){
            return true;
            }
         } 
    }
    return false;
  }
  bool isCycleUndir(){
    vector<bool> vis(v,false);
    return undirCycleHelper(0,-1,vis);
  }
};
int main(){
Graph graph(5);
graph.AddEdge(0,1);
graph.AddEdge(0,2);
graph.AddEdge(0,3);
graph.AddEdge(1,2);
graph.AddEdge(3,4);
cout<<graph.isCycleUndir()<<endl;
return 0;
}