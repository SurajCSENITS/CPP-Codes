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


bool canFill(vector<vector<char>>& board, int row, int col, char num){
    int n= board.size();
    // check row 
    for(int j=0;j<n;j++) if(board[row][j]==num) return false;
    // check column
    for(int i=0;i<n;i++) if(board[i][col]==num) return false;
    // check 3x3 cube
    int sr= (row/3)*3, sc= (col/3)*3;
    int er= sr+2, ec= sc+2;
    for(int i=sr;i<=er;i++) for(int j=sc;j<=ec;j++) if(board[i][j]==num) return false;
    
    return true;
}

void helper(vector<vector<char>>& board, int row, int col, vector<char>& v, bool* flag){
    if(row==board.size()){ // Sudoku is solved
        for(vector<char>& row: board){
            for(char ele: row) cout<< ele<< " ";
            cout<< endl;
        }
        *flag= true;
        return;
    }

    if(board[row][col]!='.'){
        if(col+1<board[row].size()) helper(board, row, col+1, v, flag);
        else helper(board, row+1, 0, v, flag);
        return;
    }

    for(char ele: v){
        if(canFill(board, row, col, ele)){
            board[row][col]= ele;
            if(col+1<board[row].size()) helper(board, row, col+1, v, flag);
            else helper(board, row+1, 0, v, flag);
    
            if(*flag==true) return; // when sudoku is solved | No need of backtracking

            // Backtracking
            board[row][col]= '.';
        }
    }

    return;
}

void solveSudoku(vector<vector<char>>& board){
    vector<char> v= {'1','2','3','4','5','6','7','8','9'};
    bool flag= false;
    helper(board, 0, 0, v, &flag); // (0,0) -> starting cell
}

int main(){

    vector<vector<char>> board= {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    solveSudoku(board);


return 0;    
}
