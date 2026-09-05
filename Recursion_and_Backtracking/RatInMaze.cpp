#include<iostream>
#include<string>
using namespace std;
void RatInMaze(int mat[4][4],int n,int r,int c,bool visited[4][4],string ans){
    if(r == n-1 && c == n-1){
        cout<<ans<<endl;
        return;
    }
    //down
    if(r+1 < n && mat[r+1][c] == 1 && !visited[r+1][c]){
        visited[r+1][c] = true;
        RatInMaze(mat,n,r+1,c,visited,ans+"D");
        visited[r+1][c] = false;
    }
    //left
    if(c-1 >= 0 && mat[r][c-1] == 1 && !visited[r][c-1]){
        visited[r][c-1] = true;
        RatInMaze(mat,n,r,c-1,visited,ans+"L");
        visited[r][c-1] = false;
    }
    //right
    if(c+1 < n && mat[r][c+1] == 1 && !visited[r][c+1]){
        visited[r][c+1] = true;
        RatInMaze(mat,n,r,c+1,visited,ans+"R");
        visited[r][c+1] = false;
    }
    //up
    if(r-1 >= 0 && mat[r-1][c] == 1 && !visited[r-1][c]){
        visited[r-1][c] = true;
        RatInMaze(mat,n,r-1,c,visited,ans+"U");
        visited[r-1][c] = false;
    }
}
int main(){
int n = 4;
int mat[4][4] = {{1,0,0,0},
                {1,1,0,1},
                {1,1,0,0},
                {0,1,1,1}};
bool visited[4][4] = {false};
if(mat[0][0] == 0){
    cout<<"No Path Exists"<<endl;
    return 0;
}
if(mat[n-1][n-1] == 0){
    cout<<"No Path Exists"<<endl;
    return 0;
}
visited[0][0] = true;
string ans = "";
RatInMaze(mat,4,0,0,visited,ans);
return 0;
}