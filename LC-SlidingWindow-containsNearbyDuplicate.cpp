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


bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(k>=nums.size()) k= nums.size()-1; // Window can not be greater then the nums size()

    unordered_set<int> s;
    // insertion of first k+1 elements
    int l=0, r= k;
    for(int i=l;i<=r;i++){
        if(s.find(nums[i])!=s.end()) return true; // element already present
        s.insert(nums[i]);
    }
    // now for rest of the elements
    while(r+1<nums.size()){
        // pop out l element
        s.erase(s.find(nums[l]));
        // right shift window
        l++; r++;       
        if(s.find(nums[r])!=s.end()) return true; // element already present
        s.insert(nums[r]);
    }
    return false;
}

int main(){

    vector<int> nums= {1,2,3,1};
    int k= 3;
    cout<< containsNearbyDuplicate(nums, k);

return 0;    
}
