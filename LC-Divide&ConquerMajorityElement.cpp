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

int frequency(vector<int>& nums, int target, int l, int r, int count= 0){
    if(l==r){
        if(nums[l]==target) count++;
    }
    else{
        int mid= (l+r)/2;
        int c1= frequency(nums, target, l, mid, count); // divide 
        int c2= frequency(nums, target, mid+1, r, count); // divide
        count= c1+c2; // merge soln
    }      
    return count;
}

int majorityElement(vector<int>& nums){
    // create a set to store the uique targets
    int n= nums.size();
    unordered_set<int> s;
    for(int ele: nums) s.insert(ele);
    for(int ele: s) if(frequency(nums, ele, 0, n-1)>(n/2)) return ele;     
    return -1;  
}

int main(){

    vector<int> nums= {2,2,1,1,1,2,2};
    cout<< majorityElement(nums);
    

return 0;    
}
