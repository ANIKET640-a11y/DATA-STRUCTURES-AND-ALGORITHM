#include<iostream>
using namespace std;

void printBoard(vector<vector<char>> board, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"---------------------\n";
}
bool isSafe(vector<vector<char>> board, int Row, int col){// check krta hai queen ko uss row,col par rakh skte hai ya nai
    int n = board.size();
    //horizontal safety

    for(int j = 0; j<n; j++){
        if(board[Row][j] == 'Q'){
            return false;
        }
        
    }

    //vertical

    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }

    //diag left

    for(int i=Row,j=col; i>=0&&j>=0; i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    //diag right
    for(int i=Row,j=col; i>=0&&j<n; i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    return true;


}

void nQueens(vector<vector<char>> board,int Row){ //recursive function which places the queen
    int n = board.size();
    if(Row == n){
        printBoard(board,Row);
        return;
    }
    for(int j = 0;  j<n; j++){ //cols
        if(isSafe(board,Row,j)){
            board[Row][j] = 'Q';
            nQueens(board, Row+1);
            board[Row][j] ='.';
    }
        
    }

}

int main(){
    vector<vector<char>> board;
    int n = 4;
    for(int i=0;i<n;i++){
        vector<char> newRow;
        for(int j=0;j<n;j++){
            newRow.push_back('.');
    }
        board.push_back(newRow);

}

nQueens(board, 0);
}
