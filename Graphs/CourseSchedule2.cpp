#include<iostream>
#include<vector>
#include<stack>
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
   void TopoSort(int src,vector<bool> &vis,stack<int> &s,vector<vector<int>> &graph){
      vis[src] = true;
      for(int i=0;i<graph.size();i++){
        int u = graph[i][1];
        int v = graph[i][0];
        if(u == src){
            if(!vis[v]){
            TopoSort(v,vis,s,graph);
            }
        }
      }
      s.push(src);
   }
    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
        int v = numCourses;
        vector<bool> vis(v,false);
        vector<bool> rec(v,false);
        vector<int> ans;

        for(int i=0;i<v;i++){
            if(!vis[v]){
             if(isCycle(i,vis,rec,graph)){
                return ans;
             }
            }
        }
         vector<bool> vis2(v,false);
         stack<int> s;
         for(int i=0;i<v;i++){
            if(!vis2[i]){
                TopoSort(i,vis2,s,graph);
            }
         }
         while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
         }
         return ans;
    }
int main(){
vector<vector<int>> graph = {{1,0},
                             {2,0},
                            {3,1},
                            {3,2}};
int numCourses = 4;
vector<int> ans = findOrder(numCourses,graph);
for(int i=0;i<ans.size();i++){//Output: [0,2,1,3]
    cout<<ans[i]<<" ";
}
return 0;
}