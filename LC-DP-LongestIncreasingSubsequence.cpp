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


int lengthOfLIS(vector<int>& nums){
    // make the map idx - vector of nges
    map<int, vector<int>> mp;
    for(int i=0;i<nums.size();i++) for(int j=i+1;j<nums.size();j++) if(nums[j]>nums[i]) mp[i].push_back(j);
    
    int maxLen= 0;
    vector<int> dp(nums.size(), 1);
    for(int i=nums.size()-1;i>=0;i--){
        for(int j=0;j<mp[i].size();j++) dp[i]= max(dp[i], 1+dp[mp[i][j]]);
        maxLen= max(maxLen, dp[i]);
    }
    return maxLen;
}

int main(){    



return 0;
}