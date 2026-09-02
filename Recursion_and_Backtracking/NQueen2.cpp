#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<char>> board,int row,int col){
int n = board.size();
//horizontal
 for(int j=0;j<n;j++){
    if(board[row][j] == 'Q'){
        return false;
    }
 }
 //vertical
 for(int i=0;i<row;i++){
    if(board[i][col] == 'Q'){
        return false;
    }
 }
 //diagonal left
 for(int i=row,j=col;j>=0 && i>=0;i--,j--){
    if(board[i][j] == 'Q'){
     return false;
    }
 }
 //diagonal right
 for(int i=row,j=col;j<n && i>=0 ;i--,j++){
     if(board[i][j] == 'Q'){
     return false;
    }
 }
 return true;
}
int NQueens(vector<vector<char>> &board,int row){
        int n = board.size();
        if(row == n){
            return 1;
        }
        int count = 0;
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j)){
             board[row][j] = 'Q';
            count += NQueens(board,row+1);
             board[row][j] = '.';
            }
        }
        return count;
}
 int totalNQueens(int n) {
        vector<vector<char>> board;
        for(int i=0;i<n;i++){
           vector<char> newRow;
          for(int j=0;j<n;j++){
          newRow.push_back('.');
          }
        board.push_back(newRow);
        }
     return NQueens(board,0);
}
int main(){
cout<<totalNQueens(4);
return 0;
}