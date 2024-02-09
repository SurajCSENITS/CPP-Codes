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

void permutations(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
    if(nums.size()==0) ans.push_back(temp);
    
    for(int i=0;i<nums.size();i++){
        temp.push_back(nums[i]);
        nums.erase(nums.begin()+i);
        permutations(nums, temp, ans);

        // backtracking
        nums.insert(nums.begin()+i, temp.back());
        temp.pop_back();
    }

    return;
}

vector<vector<int>> permute(vector<int>& nums){
    vector<int> temp;
    vector<vector<int>> ans;
    permutations(nums, temp, ans);
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
