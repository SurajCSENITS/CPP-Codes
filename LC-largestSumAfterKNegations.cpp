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


int largestSumAfterKNegations(vector<int>& nums, int k){
    // continuously find the min element and change its sign k times
    multiset<int> s;
    for(int ele: nums) s.insert(ele);

    while(k>0){
        int min= *(s.begin());
        s.erase(s.begin());
        s.insert(-min);
        k--;
    }
    // calculate sum
    int sum= 0;
    for(int ele: s) sum+=ele;
    return sum;
}

int main(){

    vector<int> nums= {4,2,3};
    int k= 1;
    cout<< largestSumAfterKNegations(nums, k);

return 0;    
}
