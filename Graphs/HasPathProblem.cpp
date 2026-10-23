#include<iostream>
#include<list>
#include<vector>
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
  bool HasPathHelper(int src,int des,vector<bool> &vis){
    if(src == des){
        return true;
    }
    vis[src] = true;
    list<int> neighbours = l[src];
    for(int v : neighbours){
        if(!vis[v]){
        if(HasPathHelper(v,des,vis)){
            return true;
        }
        }
    }
    return false;
  }
  bool HasPath(int src,int dest){
    vector<bool> vis(v,false);
    return HasPathHelper(src,dest,vis);
  } 
};
int main(){
Graph graph(7);
graph.AddEdge(0,1);
graph.AddEdge(0,2);
graph.AddEdge(1,3);
graph.AddEdge(2,4);
graph.AddEdge(3,4);
graph.AddEdge(3,5);
graph.AddEdge(4,5);
graph.AddEdge(5,6);
cout<<graph.HasPath(0,5)<<endl;
return 0;
}