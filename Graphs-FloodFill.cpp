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
#include <bits/stdc++.h>

void FloodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    int initialColor= 1;
    if(sr>=image.size()) return;
    if(sc>=image[0].size()) return;
    if(sc<0) return;
    if(sr<0) return;
    if(image[sr][sc]==newColor) return;
    if(image[sr][sc]!=initialColor) return;

    image[sr][sc]= newColor;
    FloodFill(image, sr+1, sc, newColor);
    FloodFill(image, sr, sc+1, newColor);
    FloodFill(image, sr, sc-1, newColor);
    FloodFill(image, sr-1, sc, newColor);
    
}

int main(){

    vector<vector<int>> image= {{1,1,1},{1,1,0},{1,0,1}};
    FloodFill(image, 1, 1, 2);
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].size();j++)
            cout<< image[i][j]<<" ";
        cout<< endl;
    }


return 0; 
}