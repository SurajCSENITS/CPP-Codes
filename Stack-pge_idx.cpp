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


vector<int> pge_idx(vector<int>& nums){
    // reverese nums // find nge_arr // pge_arr = rev of nge_arr
    int n= nums.size();
    reverse(nums.begin(), nums.end());

    vector<int> pge_arr(nums.size(), -1);
    stack<int> st; // to store index of nums
    st.push(0);
    for(int i=1;i<nums.size();i++){
        while(!st.empty() && nums[i]>nums[st.top()]){
            pge_arr[st.top()]= n-i-1; // *** reverse kr dene se idx kitna hoga
            st.pop();
        }
        st.push(i);
    }
    
    reverse(pge_arr.begin(), pge_arr.end());
    return pge_arr;
}


int main(){



return 0;    
}