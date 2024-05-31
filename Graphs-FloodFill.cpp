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

void helper(vector<vector<int>>& image, int r, int c, int newColor, int oldColor){
    if(r>=image.size() or r<0) return;
    if(c>=image[r].size() or c<0) return;
    if(image[r][c]!=oldColor or image[r][c]==newColor) return;

    image[r][c]= newColor;
    helper(image, r, c+1, newColor, oldColor);
    helper(image, r+1, c, newColor, oldColor);
    helper(image, r, c-1, newColor, oldColor);
    helper(image, r-1, c, newColor, oldColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
    int newColor= color;
    int oldColor= image[sr][sc];
    helper(image, sr, sc, newColor, oldColor);
    return image;
}

int main(){



return 0;    
}