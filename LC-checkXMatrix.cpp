#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>  


bool checkXMatrix(vector<vector<int>>& grid){
    int n= grid.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) if(i!=j && j!=n-i-1 && grid[i][j]!=0) return false;
        if(grid[i][i]==0 || grid[i][n-i-1]==0) return false;
    }
    return true;
}

int main(){

    vector<vector<int>> grid= {{2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2}};
    cout<< checkXMatrix(grid);
   
return 0;    
}
