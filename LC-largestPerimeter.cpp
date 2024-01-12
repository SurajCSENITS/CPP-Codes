#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>  


int largestPerimeter(vector<int>& nums){
    // Sum of the two minm side should be greater the maxm side
    // *** sort the array in desc order. Answer lengths should be contiguous
    int n= nums.size();
    sort(nums.rbegin(), nums.rend()); // reverse order sorting
    for(int i=0;i<n-2;i++) if(nums[i+1]+nums[i+2]>nums[i]) return nums[i]+nums[i+1]+nums[i+2];
    return 0; // triangle formation not possible        
}

int main(){

    vector<int> nums= {2,1,2};
    cout<< largestPerimeter(nums);

return 0;    
}
