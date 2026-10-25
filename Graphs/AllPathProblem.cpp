#include<iostream>
#include<vector>
#include<list>
#include<string>
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
    void AllPathHelper(int src,int dest,vector<bool>&vis,string &path){
     if(src == dest){
        cout<<path<<dest<<endl;
        return;
     }
     vis[src] = true;
     path += to_string(src);

     list<int> neighbors = l[src];
     for(int v : neighbors){
        if(!vis[v]){
         AllPathHelper(v,dest,vis,path);
     }
    }
    path = path.substr(0,path.size()-1);
    vis[src] = false;
}
    void AllPath(int src,int dest){
        vector<bool> vis(v,false);
        string path = "";
        AllPathHelper(src,dest,vis,path);
    }
};
int main(){
Graph graph(6,false);
graph.AddEdge(0,3);
graph.AddEdge(2,3);
graph.AddEdge(3,1);
graph.AddEdge(4,0);
graph.AddEdge(4,1);
graph.AddEdge(5,0);
graph.AddEdge(5,2);
graph.AllPath(5,1);
return 0;
}