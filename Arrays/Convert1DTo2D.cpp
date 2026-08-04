#include<iostream>
#include<vector>
using namespace std;
void ArrayTo2D(vector<int> original,int m,int n){
    int matrix[m][n];
    int k = 0;
    if(m*n == original.size()){
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        matrix[i][j] = original[k++];
      }
    }
    //print 2D matrix
  for(int i=0;i<m;i++){
   for(int j=0;j<n;j++){
    cout<<matrix[i][j]<<" ";
  }
  cout<<endl;
}
  }else{
    cout<<"Conversion is not possible";
    return;
  }
}
int main(){
vector<int> original = {1,2,3,4};
int m = 2,n = 2;
ArrayTo2D(original,m,n);
return 0;
}