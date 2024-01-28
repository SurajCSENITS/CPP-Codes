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

int minimumDifference(vector<int>& nums, int k) { // Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
    // sort -> closest elements come together
    sort(nums.begin(), nums.end());
    if(k==1) return 0;
    // make a window of size k
    vector<int> v;
    int i= 0, diff;
    for(i;i<k;i++) v.push_back(nums[i]); // insert fisrt k elements
    diff= v.back()-v.front();
    // shift window for rest of the cases
    for(i;i<nums.size();i++){
        v.erase(v.begin());
        v.push_back(nums[i]);
        diff= min(diff, v.back()-v.front());
    }
    return diff;
}

int main(){

    vector<int> nums= {9,4,1,7};
    int k= 2;
    cout<< minimumDifference(nums, k);


return 0;    
}
