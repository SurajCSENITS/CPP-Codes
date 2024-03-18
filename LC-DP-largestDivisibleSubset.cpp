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

// bool isDivisible(vector<int>& subset, int num){
//     for(int i=0;i<subset.size();i++) if(num%subset[i]!=0 and subset[i]%num!=0) return false;
//     return true;
// }

// void helper(vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans, int i= 0){
//     if(i==nums.size()){
//         if(ans.size()==0) ans.push_back(subset);
//         else if(ans.back().size()<subset.size()){
//             ans.pop_back();
//             ans.push_back(subset);
//         }
//         return;
//     }

//     if(subset.size()==0 || isDivisible(subset, nums[i])){
//         // if we take nums[i]
//         subset.push_back(nums[i]);
//         helper(nums, subset, ans, i+1);
//         // if we do not take nums[i]
//         subset.pop_back();
//         helper(nums, subset, ans, i+1);
//     }
//     else helper(nums, subset, ans, i+1);
// }

// vector<int> largestDivisibleSubset(vector<int>& nums){
//     vector<int> subset;
//     vector<vector<int>> ans;
//     helper(nums, subset, ans);
//     return ans.back();
// }


vector<int> largestDivisibleSubset(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), 1);
    int maxm= 1;

    for(int i=1;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 and dp[i]<(dp[j]+1)){
                dp[i]= dp[j]+1;
                maxm= max(maxm, dp[i]);
            }
        }
    }

    // start from the last idx
    int idx= dp.size()-1;
    vector<int> ans;
    while(idx>=0 and maxm>=1){
        if(dp[idx]==maxm and (ans.size()==0 || ans.back()%nums[idx]==0)){
            ans.push_back(nums[idx]);
            idx--; maxm--;
        }
        else idx--;
    }
    return ans;
}



int main(){

    vector<int> nums= {1,2,3};
    vector<int> subset= largestDivisibleSubset(nums);
    for(int ele: subset) cout<< ele<<" ";

return 0;    
}
