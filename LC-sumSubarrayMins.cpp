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

const int MOD= 1000000007;

vector<int> nse(vector<int>& nums){
    // increasing and decreasing curve approach
    vector<int> nse_idx(nums.size(), nums.size());
    stack<int> st; // to store index of nums
    st.push(0);
    for(int i=1;i<nums.size();i++){
        while(!st.empty() && nums[i]<=nums[st.top()]){ // *** <=
            nse_idx[st.top()]= i;
            st.pop();
        }
        st.push(i);
    }
    return nse_idx;
}

vector<int> pse(vector<int> nums){
    // reverese nums // find nse_arr // pse_arr = rev of nse_arr
    int n= nums.size();
    reverse(nums.begin(), nums.end());

    vector<int> pse_idx(nums.size(), -1);
    stack<int> st; // to store index of nums
    st.push(0);
    for(int i=1;i<nums.size();i++){
        while(!st.empty() && nums[i]<nums[st.top()]){
            pse_idx[st.top()]= n-i-1;
            st.pop();
        }
        st.push(i);
    }
    
    reverse(pse_idx.begin(), pse_idx.end());
    return pse_idx;
}

int sumSubarrayMins(vector<int>& arr){ // LC-907 https://youtu.be/9-TXIVEXX2w
    // num of subarrays in which 'k' is the smallest element
    // is = num of contiguous elements greater than 'k' in right +1 *
    // num of contiguous elements greater than 'k' in left +1
    vector<int> nse_idx= nse(arr);
    vector<int> pse_idx= pse(arr);

    int sum= 0;
    for(int i=0;i<arr.size();i++){
        long long count= (nse_idx[i]-1-i + 1)*(i-1-pse_idx[i] + 1);
        count%= MOD;
        sum= (sum%MOD + (count*arr[i])%MOD) % MOD;
    }
    return sum;
}


int main(){



return 0;
}