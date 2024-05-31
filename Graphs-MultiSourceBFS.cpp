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

// BFS for a matrix....

int getMax(vector<vector<int>>& v){
    int maxm= INT32_MIN;
    for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) maxm= max(maxm, v[i][j]);
    return maxm;
}

bool isValid(int x, int y, int m, int n){
    if(x>=m or x<0) return false;
    if(y>=n or y<0) return false;
    return true;
}

int getMinHours(vector<vector<int>>& grid){
    int m= grid.size(), n= grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> level(m, vector<int>(n, -1));
    // insert the positions of maxm value of grid into the queue
    int maxm= getMax(grid);
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(grid[i][j]==maxm) q.push({i, j}), level[i][j]= 0;

    vector<pair<int, int>> movements= {
        {0, 1}, {1, 0},
        {0, -1}, {-1, 0}
    };
    while(!q.empty()){
        pair<int, int> curr_cell= q.front();
        q.pop();
        for(pair<int, int> movement: movements){
            int childX= curr_cell.first+movement.first;
            int childY= curr_cell.second+movement.second;
            if(isValid(childX, childY, m, n) and level[childX][childY]==-1) q.push({childX, childY}), level[childX][childY]= level[curr_cell.first][curr_cell.second]+1;
        }
    }
    return getMax(level);
}

int main(){



return 0;    
}