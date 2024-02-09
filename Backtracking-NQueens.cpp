#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>  


bool canPlace(vector<vector<char>>& board, int row, int col){
    // check up side
    for(int i=row-1;i>=0;i--) if(board[i][col]=='Q') return false;
    // check down side
    for(int i=row+1;i<board.size();i++) if(board[i][col]=='Q') return false;
    // check left side
    for(int j=col-1;j>=0;j--) if(board[row][j]=='Q') return false;
    // check right side
    for(int j=col+1;j<board[row].size();j++) if(board[row][j]=='Q') return false;
    // check top-left diagonal
    for(int i=row-1, j=col-1;i>=0 && j>=0;i--, j--) if(board[i][j]=='Q') return false;
    // check top-right diagonal
    for(int i=row-1, j=col+1;i>=0 && j<board[row].size();i--, j++) if(board[i][j]=='Q') return false;
    // check bottom-left diagonal
    for(int i=row+1, j=col-1;i<board.size() && j>=0;i++, j--) if(board[i][j]=='Q') return false;
    // check bottom-right diagonal
    for(int i=row+1, j=col+1;i<board.size() && j<board[row].size();i++, j++) if(board[i][j]=='Q') return false;
    
    return true;
}

void fillRow(vector<vector<char>>& board, int row){
    int n= board.size();
    if(row==n){ // all queens have been placed
        // print the board
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<< board[i][j]<<" ";
            cout<< endl;
        }
        return;
    }

    for(int j=0;j<n;j++){
        if(canPlace(board, row, j)){
            board[row][j]= 'Q';
            fillRow(board, row+1); // after filling 'row' it is calling to fill the next row
            // backtracking
            board[row][j]= '.';
        }
    }

    return;
}

void nQueens(int n){
    vector<vector<char>> board(n, vector<char>(n, '.'));
    fillRow(board, 0); // 0 -> starting row
}


int main(){

    int n;
    cin>> n;
    nQueens(n);

return 0;    
}
