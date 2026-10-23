#include<iostream>
#include<list>
#include<vector>
#include<queue>
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
  void BFS(){
   queue<int> q;
   vector<bool> vis(v,false);

   q.push(0);
   vis[0] = true;

   while(!q.empty()){
    int u = q.front();
    q.pop();
    cout<<u<<" ";
    list<int> neighbours = l[u];
    for(int v : neighbours){
        if(!vis[v]){
        vis[v] = true;
        q.push(v);
        }
    }
   }
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
graph.BFS();
return 0;
}