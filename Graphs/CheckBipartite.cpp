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
   bool isBipartite(){
   queue<int> q;
   vector<int> color(v,-1);
   color[0] = 0;
   q.push(0);

   while(!q.empty()){
    int Curr = q.front();
    q.pop();

    list<int> neighbour = l[Curr];
    for(int v : neighbour){
        if(color[v] == -1){
          color[v] = !color[Curr];
          q.push(v);
        }else{
        if(color[v] == color[Curr]){
            return false;
        }
        }
    }
   }
   return true;
   }
};
int main(){
Graph graph(4);
graph.AddEdge(0,1);
graph.AddEdge(0,2);
graph.AddEdge(1,3);
graph.AddEdge(2,3);
cout<<graph.isBipartite()<<endl;
return 0;
}