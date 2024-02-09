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

bool checkCubes(vector<vector<char>>& board){ // optimised in sudoku Solver
    int sr, sc, er, ec;
    unordered_set<char> st;
    // (0,0)-(2,2)
    sr= 0, sc= 0, er= 2, ec= 2;
    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            if(st.count(board[i][j])!=0) return false;
            if(board[i][j]!='.') st.insert(board[i][j]);
        }
    }
    st.clear();
    // (0,3)-(2,5)
    sr= 0, sc= 3, er= 2, ec= 5;
    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            if(st.count(board[i][j])!=0) return false;
            if(board[i][j]!='.') st.insert(board[i][j]);
        }
    }
    st.clear();
    // (0,6)-(2,8)
    sr= 0, sc= 6, er= 2, ec= 8;
    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            if(st.count(board[i][j])!=0) return false;
            if(board[i][j]!='.') st.insert(board[i][j]);
        }
    }
    st.clear();
    // (3,0)-(5,2)
    sr= 3, sc= 0, er= 5, ec= 2;
    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            if(st.count(board[i][j])!=0) return false;
            if(board[i][j]!='.') st.insert(board[i][j]);
        }
    }
    st.clear();
    // (3,3)-(5,5)
    sr= 3, sc= 3, er= 5, ec= 5;
    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            if(st.count(board[i][j])!=0) return false;
            if(board[i][j]!='.') st.insert(board[i][j]);
        }
    }
    st.clear();
    // (3,6)-(5,8)
    sr= 3, sc= 6, er= 5, ec= 8;
    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            if(st.count(board[i][j])!=0) return false;
            if(board[i][j]!='.') st.insert(board[i][j]);
        }
    }
    st.clear();
    // (6,0)-(8,2)
    sr= 6, sc= 0, er= 8, ec= 2;
    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            if(st.count(board[i][j])!=0) return false;
            if(board[i][j]!='.') st.insert(board[i][j]);
        }
    }
    st.clear();
    // (6,3)-(8,5)
    sr= 6, sc= 3, er= 8, ec= 5;
    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            if(st.count(board[i][j])!=0) return false;
            if(board[i][j]!='.') st.insert(board[i][j]);
        }
    }
    st.clear();
    // (6,6)-(8,8)
    sr= 6, sc= 6, er= 8, ec= 8;
    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            if(st.count(board[i][j])!=0) return false;
            if(board[i][j]!='.') st.insert(board[i][j]);
        }
    }

    return true;
}

bool checkCell(vector<vector<char>>& board, int row, int col){
    int n= board.size();
    // check row
    for(int j=0;j<n;j++) if(j!=col and board[row][j]==board[row][col]) return false;
    // check col
    for(int i=0;i<n;i++) if(i!=row and board[i][col]==board[row][col]) return false;

    return true;
}

bool isValidSudoku(vector<vector<char>>& board){
    // check all 3x3 cubes
    if(!checkCubes(board)) return false; // 9x9 board
    // check individual rows and columns for each cell
    int n= board.size();   
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(board[i][j]!='.' and !checkCell(board, i, j)) return false;
    return true;
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
    cout<< isValidSudoku(board);

return 0;    
}
