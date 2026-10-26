#include<iostream>
#include<vector>
using namespace std;
   bool isCycle(int src,vector<bool> &vis,vector<bool> &rec,vector<vector<int>> &graph){
     vis[src] = true;
     rec[src] = true;

     for(int i=0;i<graph.size();i++){
        int u = graph[i][1];
        int v = graph[i][0];

        if(u == src){
            if(!vis[v]){
                if(isCycle(v,vis,rec,graph)){
                    return true;
                }
            }else{
                if(rec[v]){
                return true;
                }
            }
        }
     }
     rec[src] = false;
     return false;
   }
    bool canFinish(int numCourses, vector<vector<int>>& graph){
        int v = numCourses;
        vector<bool> vis(v,false);
        vector<bool> rec(v,false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(isCycle(i,vis,rec,graph)){
                    return false;
                }
            }
        }
        return true;
}
int main(){
vector<vector<int>> graph = {{1,0}};
int numCourses = 2;
cout<<canFinish(numCourses,graph)<<endl;
return 0;
}