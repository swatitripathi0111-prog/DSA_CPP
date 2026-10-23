#include<iostream>
#include<vector>
#include<list>
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
    void BFSHelper(int st,vector<bool> &vis){
    queue<int> q;
    q.push(st);
    vis[st] = true;

    while(!q.empty()){
    int Curr = q.front();
    q.pop();
    cout<<Curr<<" ";

    list<int> neighbours = l[Curr];
    for(int v : neighbours){
        if(!vis[v]){
        q.push(v);
        vis[v] = true;
        }
    }
    }
    }
    void BFS(){
    vector<bool> vis(v,false);
    for(int i=0;i<v;i++){
     if(!vis[i]){
     BFSHelper(i,vis);
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
graph.BFS();
return 0;
}