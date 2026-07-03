#include<iostream>
using namespace std;

void print(int sudoku[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoku[i][j]<<" ";

        }
        cout<<endl;
    }
}

bool isSafe(int sudoku[9][9], int r, int c, int dig){
    //vertical
    for(int i=0;i<8;i++){
        if(sudoku[i][c]==dig){
            return false;
        }
    }

    //horizontal
    for(int j=0;j<8;j++){
        if(sudoku[r][j]==dig){
            return false;
    } 
}

    //3X3 grid
    int sR = (r/3)*3; // start row value of that grid
    int sC = (c/3)*3; // start col value of that grid

    for(int i=sR;i<=sR+2;i++){
        for(int j=sC;j<=sC+2;j++){
            if(sudoku[i][j] == dig){
                return false;
            }
        }

    }

    return true;

    
}


bool sudokusolver(int sudoku[9][9], int r, int c){
    if(r == 9){
        print(sudoku);
        return true;
    }

    int nextr = r;
    int nextc = c+1;
    if(c+1 == 9){
        nextr = r+1;
        nextc = 0;
    }
    if(sudoku[r][c] != 0){
        return sudokusolver(sudoku,nextr,nextc);
    }

    for(int dig = 1; dig<=9; dig++){
        if(isSafe(sudoku,r,c,dig)){
            sudoku[r][c] = dig;
            if(sudokusolver(sudoku,nextr,nextc)){
                return true;
            }
            sudoku[r][c] = 0;
        }

    }
    return false;
}

int main() {

    int sudoku[9][9] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    if (!sudokusolver(sudoku, 0, 0)) {
        cout << "No Solution Exists";
    }

    return 0;
}