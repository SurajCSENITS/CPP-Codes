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


pair<bool, pair<int, int>> isValid(vector<vector<int>>& grid, int nextPlace, pair<int, int>& posn){
    // up left
    if((posn.first-2>=0 and posn.second-1>=0) and grid[posn.first-2][posn.second-1]==nextPlace) return {true, {posn.first-2, posn.second-1}};
    // up right
    if((posn.first-2>=0 and posn.second+1<grid[0].size()) and grid[posn.first-2][posn.second+1]==nextPlace) return {true, {posn.first-2, posn.second+1}};
    // down left
    if((posn.first+2<grid.size() and posn.second-1>=0) and grid[posn.first+2][posn.second-1]==nextPlace) return {true, {posn.first+2, posn.second-1}};
    // down right
    if((posn.first+2<grid.size() and posn.second+1<grid[0].size()) and grid[posn.first+2][posn.second+1]==nextPlace) return {true, {posn.first+2, posn.second+1}};
    // left up
    if((posn.first-1>=0 and posn.second-2>=0) and grid[posn.first-1][posn.second-2]==nextPlace) return {true, {posn.first-1, posn.second-2}};
    // left down
    if((posn.first+1<grid.size() and posn.second-2>=0) and grid[posn.first+1][posn.second-2]==nextPlace) return {true, {posn.first+1, posn.second-2}};
    // right up
    if((posn.first-1>=0 and posn.second+2<grid[0].size()) and grid[posn.first-1][posn.second+2]==nextPlace) return {true, {posn.first-1, posn.second+2}};
    // right down
    if((posn.first+1<grid.size() and posn.second+2<grid[0].size()) and grid[posn.first+1][posn.second+2]==nextPlace) return {true, {posn.first+1, posn.second+2}};

    return {false, {-1, -1}};
}

bool checkNextMove(vector<vector<int>>& grid, int move, pair<int, int>& posn){
    // Base Case -> if we reach last move
    if(move==grid.size()*grid.size()-1) return true;

    pair<bool, pair<int, int>> res= isValid(grid, move+1, posn);
    if(res.first==false) return false;
    else return checkNextMove(grid, move+1, res.second); 
}

bool checkValidGrid(vector<vector<int>>& grid){
    if(grid[0][0]!=0) return false; // should start from (0,0)
    pair<int, int> initialPosn= {0, 0};
    return checkNextMove(grid, 0, initialPosn); // starting with 0th move from top-left cell always
}

int main(){

    vector<vector<int>> grid= {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    cout<< checkValidGrid(grid);

return 0;    
}
