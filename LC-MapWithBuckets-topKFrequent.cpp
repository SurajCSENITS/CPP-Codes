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


vector<int> topKFrequent(vector<int>& nums, int k){
    // first create freq map
    unordered_map<int, int> mp;
    int maxFreq= 0;
    for(int ele: nums){
        if(mp.count(ele)==0) mp.insert({ele, 1});
        else mp[ele]+= 1;
        maxFreq= max(maxFreq, mp[ele]);
    }
    // create a bucket array -> storing all the keys having the same frequency
    vector<vector<int>> bucket(maxFreq+1);
    for(pair<int, int> p: mp) bucket[p.second].push_back(p.first); 
    // traverse from reverse to get the top k freuent elements
    vector<int> kFrequents;
    for(int i=bucket.size()-1;i>=0;i--){
        for(int ele: bucket[i]){
            kFrequents.push_back(ele);
            k--;
            if(k<=0) return kFrequents;
        }
    }
    return kFrequents;
}

int main(){

    vector<int> nums= {1,2};
    int k= 2;
    vector<int> kFrequents= topKFrequent(nums, k);
    for(int ele: kFrequents) cout<< ele<<" ";

return 0;    
}
