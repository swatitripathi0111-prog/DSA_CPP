#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
   int v;
   list<int> *l;
   bool isUndir;
public:
  Graph(int v,bool isUndir=true){
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
  bool dirCycleHelper(int src,vector<bool> &vis,vector<bool> &recPath){
    vis[src] = true;
    recPath[src] = true;

    list<int> neighbour = l[src];
    for(int v : neighbour){
     if(!vis[v]){
        if(dirCycleHelper(v,vis,recPath)){
            return true;
        }
     }else{
        if(recPath[v]){
            return true;
        }
     }
    }
    recPath[src] = false;
    return false;
  }
  bool isDirCycle(){
    vector<bool> vis(v,false);
    vector<bool> recPath(v,false);

    for(int i=0;i<v;i++){
        if(!vis[i]){
          if(dirCycleHelper(i,vis,recPath)){
            return true;
          }
        }
    }
    return false;
  }

};
int main(){
Graph graph(4,false);

graph.AddEdge(1,0);
graph.AddEdge(0,2);
graph.AddEdge(2,3);
graph.AddEdge(3,0);
cout<<graph.isDirCycle()<<endl;
return 0;
}