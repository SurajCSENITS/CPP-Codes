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

double findMaxAverage(vector<int>& nums, int k){
    deque<int> dq;
    // insertion of first k elements
    int sum= 0;
    double avg, k_= k;
    int i= 0;
    for(i;i<k;i++){
        sum+= nums[i];
        dq.push_back(nums[i]);
    }
    avg= sum/k_;
    // calculate for the rest of the elements
    while(i<nums.size()){
        // shift window to right
        sum= sum-dq.front();
        dq.pop_front();
        dq.push_back(nums[i]);
        sum+= nums[i];
        avg= max(avg, sum/k_);
        i+=1;
    }
    return avg;
}

int main(){

    vector<int> nums= {1,12,-5,-6,50,3};
    int k= 4;
    cout<< findMaxAverage(nums, k);

return 0;    
}
