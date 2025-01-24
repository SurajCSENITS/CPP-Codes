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


// see leetcode 57

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
    // in overlapping always resultant LHL = min(l1, l2) and RHL = max(r1, r2)
    int start= newInterval.front(), end= newInterval.back();
    for(int i=0;i<intervals.size();i++){
        if(start>=intervals[i].front() and start<=intervals[i].back()){
            start= intervals[i].front();
            end= max(end, intervals[i].back());
            intervals.erase(intervals.begin()+i);
            break;
        }
    }
    for(int i=0;i<intervals.size();i++){
        if(start<=intervals[i].front() and end>=intervals[i].front()){
            end= max(end, intervals[i].back());
            intervals.erase(intervals.begin()+i);
            i--;
        }
    }

    newInterval.front()= start, newInterval.back()= end;
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());     
    return intervals; 
}

int main(){




return 0;    
}
