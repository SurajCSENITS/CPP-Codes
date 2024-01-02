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