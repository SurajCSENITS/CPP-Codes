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


int numberOfArithmeticSlices(vector<int>& nums){
    vector<map<int, int>> dp(nums.size()); // count of all subsequence APs of length >=2 ending at nums[i]

    int count= 0;
    for(int i=1;i<nums.size();i++){
        for(int j=0;j<i;j++){
            long cd= long(nums[i]) - long(nums[j]);
            if(cd>INT32_MAX or cd<INT32_MIN) continue; // three elements with this cd is not possible in a integer 'nums' array
            dp[i][cd]+= dp[j][cd]+1;
            count+= dp[j][cd];
        }
    }
    return count;
}

int main(){



return 0;
}