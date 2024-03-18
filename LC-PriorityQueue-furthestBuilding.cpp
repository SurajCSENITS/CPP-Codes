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

// int helper(vector<int>& heights, int bricks, int ladders, int curr){ // maxm value that curr can reach
//     // Base Case
//     if(curr==heights.size()-1 || bricks<heights[curr+1]-heights[curr] && ladders==0) return curr;
//     // if next building has less height
//     if(heights[curr+1]<heights[curr]) return helper(heights, bricks, ladders, curr+1);

//     // if next building has more height
//     int distL= -1, distB= -1;
//     if(ladders>0) distL= helper(heights, bricks, ladders-1, curr+1);
//     if(bricks>=heights[curr+1]-heights[curr]) distB= helper(heights, bricks-(heights[curr+1]-heights[curr]), ladders, curr+1);

//     curr= max(distL, distB);
//     return curr;
// }

// int furthestBuilding(vector<int>& heights, int bricks, int ladders){
//     return helper(heights, bricks, ladders, 0); // 0 -> starting building
// }


int furthestBuilding(vector<int>& heights, int bricks, int ladders){
    // Corner Cases
    if(heights.size()==1) return 0;
    // zahan tak bhi jaa rhe h, waha tak ke top larger jumps k liye ladders and rest of smaller jumps k liye bricks
    priority_queue<int, vector<int>, greater<int>> min_heap; // we can use set also
    // first use all the ladders and push the jumps into the minheap
    for(int i=1;i<heights.size();i++){ // currently on the i-1 row
        int diff= heights[i]-heights[i-1];
        if(diff<=0) continue; // jump on next
        // when diff>0
        if(ladders>0){
            min_heap.push(diff);
            ladders--;
            continue; // jump on next
        }
        // if ladders are exausted -> try to optimize
        if(!min_heap.empty() && diff>min_heap.top()){
            // can we fill top of heap with available bricks
            if(bricks>=min_heap.top()){
                bricks-= min_heap.top();
                min_heap.pop();
                min_heap.push(diff);
                continue; // jump on next
            }
            return i-1;
        }
        // diff <= top of heap
        if(bricks>=diff){
            bricks-= diff;
            continue;
        }
        return i-1;
    }
    // reached last building
    return heights.size()-1;
}



int main(){

    vector<int> heights= {4,2,7,6,9,14,12};
    int bricks= 5;
    int ladders= 1;
    cout<< furthestBuilding(heights, bricks, ladders);

return 0;    
}
