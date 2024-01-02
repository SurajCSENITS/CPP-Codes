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


int getSurfaceArea(vector<vector<int>>& grid, int r, int c){
    if(grid[r][c]==0) return 0;

    int sa= 2;// 2*(1x1); // front and back    
    
    if(r+1<grid.size()){ // bottom surface
        int val= grid[r][c]-grid[r+1][c];
        if(val>0) sa= sa+val*1;
    }
    else sa= sa+grid[r][c]*1;

    if(r-1>=0){ // up suraface
        int val= grid[r][c]-grid[r-1][c];
        if(val>0) sa= sa+val*1;
    }
    else sa= sa+grid[r][c]*1;

    if(c+1<grid[r].size()){ // right surface
        int val= grid[r][c]-grid[r][c+1];
        if(val>0) sa= sa+val*1;
    }
    else sa= sa+grid[r][c]*1;

    if(c-1>=0){ // left surface
        int val= grid[r][c]-grid[r][c-1];
        if(val>0) sa= sa+val*1;
    }
    else sa= sa+grid[r][c]*1;

    return sa;

}

int surfaceArea(vector<vector<int>>& grid){
    int totalSurfaceArea= 0;
    int n= grid.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            totalSurfaceArea+= getSurfaceArea(grid, i, j);
        }
    }
    return totalSurfaceArea;
}

int main(){

    vector<vector<int>> grid= {{1,1,1},{1,0,1},{1,1,1}};
    cout<< surfaceArea(grid);
   
return 0;    
}
