#include<iostream>
using namespace std;
//n->rows and m->colunm
//1]print the transpose
void Transpose1(int matrix[3][3],int n,int m){
    for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
      cout<<matrix[j][i]<<" ";
     }
     cout<<endl;
    }
}
//2] Transpose and store it into another matrix
void Transpose2(int A[3][3],int n,int m){
    int B[m][n];
    for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
      B[i][j] = A[j][i];
     }
    }
    for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
      cout<<B[i][j]<<" ";
     }
     cout<<endl;
    }
}
//3] for NXN matrix
void Transpose3(int matrix[3][3],int n){
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
    swap(matrix[i][j],matrix[j][i]);
    }
  }
  //Transposed matrix
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main(){
int matrix1[3][3] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
int matrix2[2][3] = {{1,2,3},
                     {4,5,6}};
Transpose1(matrix2,2,3);
Transpose2(matrix2,2,3);
Transpose3(matrix1,3);
 return 0;
}