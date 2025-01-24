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
#include <tuple>
#include <bits/stdc++.h>

// Outcomes: 
// How to calculate line overlaps
// How to calculate rectangle overlaps
// Solution : https://www.youtube.com/watch?v=9pmaSnUMxMY (Take projection on X and Y axis)

int getLineOverlap(int ax1, int ax2, int bx1, int bx2){
    if(ax1>=bx2 or ax2<=bx1) return 0; // No overlap condition
    if(ax2>=bx2 and ax1<=bx2 and ax1>=bx1) return bx2-ax1; // a ahead of b & overlaping
    if(ax1<=bx1 and ax2>=bx1 and ax2<=bx2) return ax2-bx1; // a behind of b & overlaping
    if(ax1>=bx1 and ax2<=bx2) return ax2-ax1; // a inside b
    if(bx1>=ax1 and bx2<=ax2) return bx2-bx1; // b inside a
    return -1;
}

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int rect1_Area= (ax2-ax1)*(ay2-ay1);
    int rect2_Area= (bx2-bx1)*(by2-by1);
    
    int overLapXwidth= getLineOverlap(ax1, ax2, bx1, bx2);
    int overLapYwidth= getLineOverlap(ay1, ay2, by1, by2);
    int overlaped_Area= overLapXwidth*overLapYwidth;
    
    int area_covered= rect1_Area+rect2_Area-overlaped_Area;
    return area_covered;
}

int main(){


return 0;
}