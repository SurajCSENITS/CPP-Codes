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

void fourDirnRatInMaze(int sr, int sc, int er, int ec, vector<vector<bool>>& isVisited, string path= ""){
    if(sr<0 || sc<0) return;
    if(sr>er || sc>ec) return;
    if(isVisited[sr][sc]==true) return;
    if(sr==er && sc==ec){
        cout<< path<< endl;
        return;
    }

    isVisited[sr][sc]= true;
    // go right
    fourDirnRatInMaze(sr, sc+1, er, ec, isVisited, path+'R');
    // go down
    fourDirnRatInMaze(sr+1, sc, er, ec, isVisited, path+'D');
    // go left
    fourDirnRatInMaze(sr, sc-1, er, ec, isVisited, path+'L');
    // go up
    fourDirnRatInMaze(sr-1, sc, er, ec, isVisited, path+'U');
    // backtracking
    isVisited[sr][sc]= false;
}

int main(){

    // for only 2 dirn move -> backtracking is not required
    
    vector<vector<bool>> isVisited(3);
    for(auto &row: isVisited) row.resize(3, false);
    fourDirnRatInMaze(0, 0, 2, 2, isVisited);
    

return 0;    
}
