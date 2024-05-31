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

int getX(string str){ return str[0]-'a'; }
int getY(string str){ return str[1]-'1'; }

bool isValid(int x, int y){
    if(x>=8 or x<0) return false;
    if(y>=8 or y<0) return false;
    return true;
}

int getMinMoves(string source, string dest){
    int sourceX= getX(source);
    int sourceY= getY(source);
    int destX= getX(dest);
    int destY= getY(dest);

    queue<pair<int, int>> q;
    vector<vector<int>> level(8, vector<int>(8, INT32_MAX));
    vector<vector<bool>> isVisited(8, vector<bool>(8, false));
    vector<pair<int, int>> movements= {
        {-1, 2}, {1, 2},
        {-1, -2}, {1, -2},
        {2, -1}, {2, 1},
        {-2, -1}, {-2, 1}
    };

    q.push({sourceX, sourceY});
    level[sourceX][sourceY]= 0;
    isVisited[sourceX][sourceY]= true;
    while(!q.empty()){
        int x= q.front().first, y= q.front().second;
        // insert children of current cell
        for(pair<int, int> movement: movements){
            int childX= x+movement.first, childY= y+movement.second;
            if(isValid(childX, childY) and !isVisited[childX][childY]){
                q.push({childX, childY});
                isVisited[childX][childY]= true;
                level[childX][childY]= level[x][y]+1;
            }
        }
        q.pop();
        if(level[destX][destY]!=INT32_MAX) break;
    }
    return level[destX][destY];
}

int main(){

    string source;
    string dest;
    cin>> source>> dest;
    cout<< getMinMoves(source, dest);

return 0;    
}