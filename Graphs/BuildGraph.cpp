#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
    int v;
    list<int>* l;
public:
   Graph(int v){
    this-> v = v;
    l = new list<int> [v];
   }
   void AddEdge(int u,int v){
    l[u].push_back(v);
    l[v].push_back(u);
   }
   void Print(){
    for(int u=0;u<v;u++){
     list<int> neighbours = l[u];
     cout<<u<<":";
     for(int v : neighbours){
        cout<<v<<" ";
     }
     cout<<endl;
    }
   }
};
int main(){
Graph graph(5);
graph.AddEdge(0,1);
graph.AddEdge(1,2);
graph.AddEdge(1,3);
graph.AddEdge(2,3);
graph.AddEdge(2,4);
graph.Print();
return 0; 
}