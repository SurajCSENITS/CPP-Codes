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
    // up left
    if((row-2>=0 and col-1>=0) and board[row-2][col-1]=='K') return false;
    // up right
    if((row-2>=0 and col+1<board[0].size()) and board[row-2][col+1]=='K') return false;
    // down left
    if((row+2<board.size() and col-1>=0) and board[row+2][col-1]=='K') return false;
    // down right
    if((row+2<board.size() and col+1<board[0].size()) and board[row+2][col+1]=='K') return false;
    // left up
    if((row-1>=0 and col-2>=0) and board[row-1][col-2]=='K') return false;
    // left down
    if((row+1<board.size() and col-2>=0) and board[row+1][col-2]=='K') return false;
    // right up
    if((row-1>=0 and col+2<board[0].size()) and board[row-1][col+2]=='K') return false;
    // right down
    if((row+1<board.size() and col+2<board[0].size()) and board[row+1][col+2]=='K') return false;

    return true;
}

void helper(vector<vector<char>>& board, int row, int col, int* ans, int count= 0){
    // Base Case
    if(row==board.size()){
        // printing all the boards
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++) cout<< board[i][j];
            cout<< endl;
        }
        cout<< endl;
        // printing boards having a specified num of knights eg: 5
        if(count==5){
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[i].size();j++) cout<< board[i][j];
                cout<< endl;
            }
            cout<< endl;
        }
        // update ans
        *ans= max(*ans, count);
        return;
    }
    
    if(canPlace(board, row, col)){
        board[row][col]= 'K';
        if(col+1<board[row].size()) helper(board, row, col+1, ans, count+1);
        else helper(board, row+1, 0, ans, count+1); // start from 0th col for the next row
        // backtracking
        board[row][col]= 'X';
    }

    if(col+1<board[row].size()) helper(board, row, col+1, ans, count);
    else helper(board, row+1, 0, ans, count); // start from 0th col for the next row

    return;
}

int maxKnights(int n){
    vector<vector<char>> board(n, vector<char>(n, 'X'));
    int ans= 0;
    helper(board, 0, 0, &ans); // 0,0 -> starting cell
    return ans;
}

int main(){

    int n;
    cin>> n;
    int ans= maxKnights(n);
    cout<< ans;

return 0;    
}
