#include<iostream>
using namespace std;
int main(){
int matrix[3][3] = {{1,2,3},
                   {4,5,6},
                   {7,8,9}};
int n = 3,m=3;
int tne = n*m;
int minr = 0;
int minc = 0;
int maxr = n-1;
int maxc = m-1;
int count = 0;
while(count < tne){
  //print minimum row
  for(int j=minc;j<=maxc && count<tne;j++){
    cout<<matrix[minr][j]<<" ";
    count++;
  }
  minr++;
  //print maximum column
  for(int i=minr;i<=maxr && count < tne;i++){
    cout<<matrix[i][maxc]<<" ";
    count++;
  }
  maxc--;
  //print maximum row
  for(int j=maxc;j>=minc && count < tne;j--){
    cout<<matrix[maxr][j]<<" ";
    count++;
  }
  maxr--;
  //print minimum column
  for(int i=maxr;i>=minr && count < tne;i--){
    cout<<matrix[i][minc]<<" ";
    count++;
  }
  minc++;
}
 return 0;
}