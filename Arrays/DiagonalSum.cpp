#include<iostream>
using namespace std;
//Approach - 1 with time complexity of O(n^2)
int DiagonalSum1(int matrix[3][3],int n){
  int sum = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
     if(j == i){
      sum  += matrix[i][j];
     }else if(j == n-i-1){
        sum += matrix[i][j];
     }
    }
  }
  return sum;
}
//Approach - 2 with time complexity of O(n)
int DiagoanlSum2(int matrix[3][3],int n){
   int sum = 0;
   for(int i=0;i<n;i++){
    sum += matrix[i][i];
    if(i != n-i-1){
     sum += matrix[i][n-i-1];
    }
   }
   return sum;
}
int main(){
int matrix[3][3] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
cout<<"Diagonal Sum = " <<DiagonalSum1(matrix,3)<<endl;
cout<<"Diagonal Sum  = "<<DiagoanlSum2(matrix,3)<<endl;
return 0;
}