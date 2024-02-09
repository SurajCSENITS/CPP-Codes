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

void swap(int* a, int* b){
    int temp= *a;
    *a= *b;
    *b= temp;
}

void permutations(vector<int>& nums, int idx, vector<vector<int>>& ans){
    if(idx==nums.size()-1) ans.push_back(nums);

    for(int i=idx;i<nums.size();i++){
        // swap nums[i], nums[idx] and increament idx by 1
        swap(&nums[i], &nums[idx]);
        permutations(nums, idx+1, ans);

        // backtracking
        // again swap nums[i] and nums[idx] and decreament idx* by 1
        swap(&nums[i], &nums[idx]);
    }

    return;
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    permutations(nums, 0, ans);
    return ans;
}

int main(){

    vector<int> nums= {1,2,3};
    vector<vector<int>> ans= permute(nums);
    for(vector<int>& row: ans){
        for(int ele: row) cout<< ele<<" ";
        cout<< endl;
    }

return 0;    
}
