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
    void DFSHelper(int u,vector<bool> &vis){
        cout<<u<<" ";
        vis[u] = true;

        list<int> neighbour = l[u];
        for(int v : neighbour){
            if(!vis[v]){
            DFSHelper(v,vis);
            }
        }
    }
    void DFS(){
    vector<bool> vis(v,false);
    for(int i=0;i<v;i++){
      if(!vis[i]){
        DFSHelper(i,vis);
        cout<<endl;
      }
    }
    }
};
int main(){
Graph graph(10);
graph.AddEdge(0,2);
graph.AddEdge(2,5);
graph.AddEdge(1,6);
graph.AddEdge(6,4);
graph.AddEdge(4,3);
graph.AddEdge(4,9);
graph.AddEdge(7,3);
graph.AddEdge(8,3);
graph.DFS();
return 0;
}