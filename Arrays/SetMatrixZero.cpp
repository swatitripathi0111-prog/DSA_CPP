#include<iostream>
#include<vector>
using namespace std;
void setZeroes(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    bool FirstRowImpacted = false;
    bool FirstColImpacted = false;

    for(int col=0;col<n;col++){
        if(matrix[0][col] == 0){
          FirstRowImpacted = true;
          break; 
        }
    }
    for(int row=0;row<m;row++){
     if(matrix[row][0] == 0){
        FirstColImpacted = true;
        break;
     }
    }
    for(int i=1;i<m;i++){
     for(int j=1;j<n;j++){
      if(matrix[i][j] == 0){
        matrix[0][j] = 0;
        matrix[i][0] = 0;
      }
     }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
         if(matrix[0][j] == 0 || matrix[i][0] == 0){
            matrix[i][j] = 0;
         }
        }
    }
    if(FirstColImpacted){
      for(int i=0;i<m;i++){
        matrix[i][0] = 0;
      }
    }
    if(FirstRowImpacted){
     for(int j=0;j<n;j++){
        matrix[0][j] = 0;
      }
    }
}
int main(){
vector<vector<int>> matrix = {{1,2,3,4},
                               {5,6,0,8},
                             {9,10,11,12}};
setZeroes(matrix);
for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[0].size();j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}
 return 0;
}