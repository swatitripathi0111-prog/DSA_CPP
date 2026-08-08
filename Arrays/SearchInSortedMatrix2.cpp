#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int st = 0;
    int end = n*m-1;
    while(st <= end){
    int mid = (st+end)/2;
    int row = mid/n;
    int col = mid%n;
    if(matrix[row][col] == target){
     cout<<row<<","<<col<<endl;
     return true;
    }else if(matrix[row][col] < target){
        st = mid+1;
    }else{
        end = mid-1;
    }
    }
 return false;
}
int main(){
vector<vector<int>> matrix = {{1,3,5,7},
                            {10,11,16,20},
                            {23,30,34,60}};
cout<<searchMatrix(matrix,16)<<endl;
cout<<searchMatrix(matrix,25)<<endl;
 return 0;
}