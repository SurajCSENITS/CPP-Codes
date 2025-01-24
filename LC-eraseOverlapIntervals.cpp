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

int eraseOverlapIntervals(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end());
    int prevEndVal= intervals[0][1];
    int popOuts= 0;
    for(int i=1;i<intervals.size();i++){
        if(intervals[1][0]<prevEndVal){
            popOuts++;
            prevEndVal= min(prevEndVal, intervals[i][1]);
            continue;
        }
        prevEndVal= intervals[i][1];
    } 
    return popOuts;
}

int main(){



return 0;
}