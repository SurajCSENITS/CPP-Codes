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

void removeQueen(vector<vector<char>>& board, int row, int col){ board[row][col]= 'X'; }
   
vector<vector<char>> nQueens(int n){
    vector<vector<char>> board(n, vector<char>(n, 'X'));
    int i= 0, j= 0;
    bool flag= false;
    vector<int> prevCol;
    while(i<board.size()){
        for(j;j<board[i].size();j++){
            if(canPlace(board, i, j)){
                board[i][j]= 'Q';
                flag= true;
                break;
            }
        }
        if(!flag){
            if(i-1<0) return board; // special case: when no configurations possible           
            removeQueen(board, i-1, prevCol.back());
            i= i-1;
            j= prevCol.back()+1;
            prevCol.pop_back();
        }
        else{
            i++;
            prevCol.push_back(j);
            j= 0;
            flag= false;
        }
    }

    return board;
}


int main(){

    int n;
    cin>> n;
    vector<vector<char>> board= nQueens(n);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++) cout<< board[i][j]<<" ";
        cout<< endl;
    }

return 0;    
}
