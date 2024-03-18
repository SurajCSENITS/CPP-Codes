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


int findMin(vector<int>& nums){
    int lo= 0, hi= nums.size()-1;
    // check if left and right elements are equal
    int candidate= INT32_MAX;
    if(nums[lo]==nums[hi]){
        while(lo<=hi and nums[lo]==nums[hi]){
            candidate= min(candidate, nums[lo]);
            lo++;
            hi--;
        }
        if(lo>hi) return candidate; // ***
    }
    // check if normal sorted
    if(nums[lo]<nums[hi]) return min(candidate, nums[lo]); // *** [0,1,2,0]
    // now its the normal rotated array 
    while(lo<=hi){
        int mid= (lo+hi)/2;
        if(nums[mid]>nums[mid+1]) return nums[mid+1];
        if(nums[mid]<nums[mid-1]) return nums[mid];
        if(nums[mid]>=nums[lo]) lo= mid+1; // ***
        else hi= mid-1;
    }
    return -1;
}


int main(){



return 0;    
}
