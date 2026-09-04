#include<iostream>
using namespace std;
int n = 8; 
void PrintBoard(int mat[8][8]){
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<mat[i][j]<<" ";
    }
   cout<<endl;
 }
}
bool isSafe(int NewX,int NewY,bool visited[8][8]){
    if(NewX >= 0 && NewY >= 0 && NewX < n && NewY < n && !visited[NewX][NewY]){
        return true;
    }
    return false;
}
bool KnightTour2(int mat[8][8],int CurrRow,int CurrCol,bool visited[8][8],int MoveCount){
   if(MoveCount == n*n){
    PrintBoard(mat);
    return true;
   }
   int RowMove[] = {-2,-1,1,2,2,1,-1,-2};
   int ColMove[] = {1,2,2,1,-1,-2,-2,-1};
   for(int i=0;i<n;i++){
    int NewX = CurrRow + RowMove[i];
    int NewY = CurrCol + ColMove[i];
    if(isSafe(NewX,NewY,visited)){
        mat[NewX][NewY] = MoveCount;
        visited[NewX][NewY] = true;
       if(KnightTour2(mat,NewX,NewY,visited,MoveCount+1)){
        return true;
       }
       mat[NewX][NewY] = -1;
       visited[NewX][NewY] = false;
    }
   }
   return false;
}
int main(){
int mat[8][8];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      mat[i][j] = -1;
    }
 }
 bool visited[8][8] = {false};
 mat[0][0] = 0;
 visited[0][0] = true;
if(!(KnightTour2(mat,0,0,visited,1))){
 cout<<"NO SOLUTION EXIST";
}
 return 0;
}