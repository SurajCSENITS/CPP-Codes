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


bool isAP(int a, int b, int c){ return b-a == c-b; }
   
int numberOfArithmeticSlices(vector<int>& nums){
    vector<int> dp(nums.size(), 0); // dp[i] = num of APs finishing at ith index
    int count= 0;
    for(int i=2;i<nums.size();i++){
        if(!isAP(nums[i], nums[i-1], nums[i-2])) continue;
        dp[i]= dp[i-1]+1; // all the APs finishing at i-1 will extend upto i, and one extra AP of last* 3 elements
        count+= dp[i];
    }
    return count;
}

int main(){



return 0;
}