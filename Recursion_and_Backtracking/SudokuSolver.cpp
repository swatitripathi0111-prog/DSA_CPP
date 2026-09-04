#include<iostream>
using namespace std;
void PrintSudoku(int sudoku[9][9]){
    for(int i=0;i<9;i++){
     for(int j=0;j<9;j++){
         cout<<sudoku[i][j]<<" ";
    }
        cout<<endl;
    }
}
bool isSafe(int sudoku[9][9],int row,int col,int digit){
   //vertical
   for(int i=0;i<=8;i++){
    if(sudoku[i][col] == digit){
        return false;
    }
   }
   //horizontal
   for(int j=0;j<=8;j++){
    if(sudoku[row][j] == digit){
        return false;
    }
   }
   //grid3X3
   int StartRow = (row/3)*3;
   int StartCol = (col/3)*3;

   for(int i=StartRow;i<=StartRow+2;i++){
      for(int j=StartCol;j<StartCol+2;j++){
         if(sudoku[i][j] == digit){
            return false;
         }
      }
   }
   return true;
}
bool SudokuSolver(int sudoku[9][9],int row,int col){
   if(row == 9){
    PrintSudoku(sudoku);
    return true;
   }
   int NextRow = row;
   int NextCol = col+1;
   if(col+1 == 9){
    NextRow = row+1;
    NextCol = 0;
   }
   if(sudoku[row][col] != 0){
     return SudokuSolver(sudoku,NextRow,NextCol);
   }
   for(int digit=1;digit<=9;digit++){
    if(isSafe(sudoku,row,col,digit)){
        sudoku[row][col] = digit;
        if(SudokuSolver(sudoku,NextRow,NextCol)){
            return true;
        }
        sudoku[row][col] = 0;
    }
   }
   return false;
}
int main(){
int sudoku[9][9] = {{0,0,8,0,0,0,0,0,0},
                   {4,9,0,1,5,7,0,0,2},
                    {0,0,3,0,0,4,1,9,0},
                    {1,8,5,0,6,0,0,2,0},
                    {0,0,0,0,2,0,0,6,0},
                    {9,6,0,4,0,5,3,0,0},
                    {0,3,0,0,7,2,0,0,4},
                    {0,4,9,0,3,0,0,5,7},
                     {8,2,7,0,0,9,0,1,3}};
SudokuSolver(sudoku,0,0);
 return 0;
}