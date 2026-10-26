#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
class Graph{
  int v;
  list<int> *l;
  bool isUndir;
public:
  Graph(int v,bool isUndir = true){
    this->v = v;
    l = new list<int>[v];
    this->isUndir = isUndir;
  }
  void AddEdge(int u,int v){
    l[u].push_back(v);
    if(isUndir){
    l[v].push_back(u);
    }
  }
  void TopoSortHelper(int src,vector<bool> &vis,stack<int> &s){
    vis[src] = true;
    list<int> neighbours = l[src];

    for(int v : neighbours){
        if(!vis[v]){
        TopoSortHelper(v,vis,s);
        }
    }
    s.push(src);
  }
  void TopoSort(){
    vector<bool> vis(v,false);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!vis[i]){
        TopoSortHelper(i,vis,s);
        }
    }
    while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
    }
  }
};
int main(){
Graph graph(6,false);
graph.AddEdge(2,3);
graph.AddEdge(3,1);
graph.AddEdge(4,0);
graph.AddEdge(4,1);
graph.AddEdge(5,0);
graph.AddEdge(5,2);
graph.TopoSort();
return 0;
}