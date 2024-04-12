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

// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


int minSubArrayLen(int target, vector<int>& nums){
    int sum= 0, candidate= INT32_MAX;
    deque<int> dq;
    for(int i=0;i<nums.size();i++){
        dq.push_back(nums[i]);
        sum+= nums[i];
        while(sum>=target){
            int n= dq.size();
            candidate= min(candidate, n);
            sum-= dq.front();
            dq.pop_front();
        }
    }
    if(candidate==INT32_MAX) return 0; // does not exist
    return candidate;
}

int main(){

    vector<int> nums= {2,3,1,2,4,3};
    int target= 7;
    cout<< minSubArrayLen(target, nums);

return 0;    
}
