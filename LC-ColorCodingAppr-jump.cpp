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


int jump(vector<int>& nums){ // YT -> NeetCode LC-45
    // Corner Case
    if(nums.size()==1) return 0;

    int l= 0, r= 0;
    int range= 0; // 0th range
    while(true){
        int furthest= 0;
        for(int i=l;i<=r;i++){
            furthest= max(furthest, i+nums[i]);
            if(furthest>=nums.size()-1){
                furthest= nums.size()-1;
                break;
            }
        }
        // define new range
        range++;
        l= r+1;
        r= furthest;
        if(r==nums.size()-1) return range;
    }
    return range;
}

int main(){


return 0;    
}
