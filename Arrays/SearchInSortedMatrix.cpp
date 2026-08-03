#include<iostream>
#include<vector>
using namespace std;
bool SearchInSortedMatrix(vector<vector<int>> matrix,int key){
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;
    int col = m-1;
    while(row < n && col >= 0){
    if(matrix[row][col] == key){
        cout<<"("<<row<<","<<col<<")"<<endl;
        return true;
    }else if(matrix[row][col] >  key){
        col--;
    }else{
        row++;
    }
    }
    return false;
}
int main(){
vector<vector<int>> matrix = {{10,20,30,40},
                             {15,25,35,45},
                            {27,29,37,48},
                             {32,33,39,50}};
cout<<SearchInSortedMatrix(matrix,33)<<endl;
 return 0;
}

