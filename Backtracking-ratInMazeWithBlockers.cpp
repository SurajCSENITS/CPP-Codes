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

void ratInMazeWithBlockers(int sr, int sc, int er, int ec, vector<vector<int>>& maze, string path= ""){
    // In matrix 'maze'
    // 1 -> not visited
    // -1 -> visited
    // 0 -> blocker
    if(sr<0 || sc<0) return;
    if(sr>er || sc>ec) return;
    if(maze[sr][sc]==0) return;
    if(maze[sr][sc]==-1) return;
    if(sr==er && sc==ec){
        cout<< path<< endl;
        return;
    }

    maze[sr][sc]= -1;
    // go right
    ratInMazeWithBlockers(sr, sc+1, er, ec, maze, path+'R');
    // go down
    ratInMazeWithBlockers(sr+1, sc, er, ec, maze, path+'D');
    // go left
    ratInMazeWithBlockers(sr, sc-1, er, ec, maze, path+'L');
    // go up
    ratInMazeWithBlockers(sr-1, sc, er, ec, maze, path+'U');
    // backtracking
    maze[sr][sc]= 1;
}

int main(){


    vector<vector<int>> maze= {{1,0,1,1},{1,1,1,1},{1,1,0,1}};
    ratInMazeWithBlockers(0, 0, 2, 3, maze);
    

return 0;    
}
