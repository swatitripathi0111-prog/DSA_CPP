#include<iostream>
#include<vector>
using namespace std;
bool WordSearch(vector<vector<char>>& board, string word,int r,int c,int i,vector<vector<bool>>&visited,string ans){
    int n = board.size();
    int m = board[0].size();
    if(ans == word){
    return true;
    }
    //down 
    if(r+1 < n && board[r+1][c] == word[i+1] && !visited[r+1][c]){
        ans.push_back(board[r+1][c]);
        visited[r+1][c] = true;
        if(WordSearch(board,word,r+1,c,i+1,visited,ans)){
            return true;
        }
        ans.pop_back();
        visited[r+1][c] = false;
    }
    //left 
    if(c-1 >= 0 && board[r][c-1] == word[i+1] && !visited[r][c-1]){
        ans.push_back(board[r][c-1]);
        visited[r][c-1] = true;
        if(WordSearch(board,word,r,c-1,i+1,visited,ans)){
            return true;
        }
        ans.pop_back();
        visited[r][c-1] = false;
    }
    //right
    if(c+1 < m && board[r][c+1] == word[i+1] && !visited[r][c+1]){
        ans.push_back(board[r][c+1]);
        visited[r][c+1] = true;
        if(WordSearch(board,word,r,c+1,i+1,visited,ans)){
            return true;
        }
        ans.pop_back();
        visited[r][c+1] = false;
    }
    //up
    if(r-1 >= 0 && board[r-1][c] == word[i+1] && !visited[r-1][c]){
        ans.push_back(board[r-1][c]);
        visited[r-1][c] = true;
        if(WordSearch(board,word,r-1,c,i+1,visited,ans)){
            return true;
        }
        ans.pop_back();
        visited[r-1][c] = false;
    }
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int r=0;r<n;r++){
    for(int c=0;c<m;c++){
     if(board[r][c] == word[0]){
        visited[r][c] = true;
        string ans = "";
        ans.push_back(board[r][c]);
        if(WordSearch(board,word,r,c,0,visited,ans)){
            return true;
            visited[r][c] = false;
        }
     }
    }
    }
    return false;
}
int main(){
vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
string word =  "ABCCED";
cout<<exist(board,word);
return 0;
}