#include<iostream>
using namespace std;
void PrintArr(int matrix[3][3],int n){
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
     cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
    }
}
void RotateMatrix(int matrix[3][3],int n){
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
     swap(matrix[i][j],matrix[j][i]);
    }
  }
  for(int i=0;i<n;i++){
    int j = 0;
    int k = n-1;
    while(j<k){
    swap(matrix[i][j],matrix[i][k]);
    j++;
    k--;
    }
  }
  PrintArr(matrix,3);
}
int main(){
int matrix[3][3] = {{1,2,3},
                    {4,5,6},
                     {7,8,9}};
RotateMatrix(matrix,3);
  return 0;
}