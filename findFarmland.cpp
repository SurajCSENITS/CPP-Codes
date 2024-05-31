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

void helper(vector<vector<int>>& land, vector<vector<bool>>& isVisited, int i, int j, int& r_max, int& c_max){
    if(i>=land.size() or i<0) return;
    if(j>=land[0].size() or j<0) return;
    if(land[i][j]==0 or isVisited[i][j]) return;

    isVisited[i][j]= true;
    r_max= max(r_max, i);
    c_max= max(c_max, j);

    helper(land, isVisited, i, j+1, r_max, c_max);
    helper(land, isVisited, i+1, j, r_max, c_max);
    helper(land, isVisited, i, j-1, r_max, c_max);
    helper(land, isVisited, i-1, j, r_max, c_max);
}

vector<vector<int>> findFarmland(vector<vector<int>>& land){
    int m= land.size(), n= land[0].size();
    vector<vector<int>> answer;
    vector<vector<bool>> isVisited(m, vector<bool>(n, false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(isVisited[i][j] or land[i][j]==0) continue;
            vector<int> group;
            group.push_back(i), group.push_back(j);
            int r_max= i, c_max= j;
            helper(land, isVisited, i, j, r_max, c_max);
            group.push_back(r_max), group.push_back(c_max);
            answer.push_back(group);
        }
    }
    return answer;
}

int main(){



return 0;
}