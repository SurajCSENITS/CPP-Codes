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

vector<int> nge(vector<int>& nums){
    // increasing and decreasing curve approach
    vector<int> nge_arr(nums.size(), -1);
    stack<int> st; // to store index of nums
    st.push(0);
    for(int i=1;i<nums.size();i++){
        while(!st.empty() && nums[i]>nums[st.top()]){
            nge_arr[st.top()]= nums[i];
            st.pop();
        }
        st.push(i);
    }
    return nge_arr;
}

vector<int> nse(vector<int>& nums){
    // increasing and decreasing curve approach
    vector<int> nse_arr(nums.size(), -1);
    stack<int> st; // to store index of nums
    st.push(0);
    for(int i=1;i<nums.size();i++){
        while(!st.empty() && nums[i]<nums[st.top()]){
            nse_arr[st.top()]= nums[i];
            st.pop();
        }
        st.push(i);
    }
    return nse_arr;
}

vector<int> pge(vector<int>& nums){
    // reverese nums // find nge_arr // pge_arr = rev of nge_arr
    reverse(nums.begin(), nums.end());

    vector<int> pge_arr(nums.size(), -1);
    stack<int> st; // to store index of nums
    st.push(0);
    for(int i=1;i<nums.size();i++){
        while(!st.empty() && nums[i]>nums[st.top()]){
            pge_arr[st.top()]= nums[i];
            st.pop();
        }
        st.push(i);
    }
    
    reverse(pge_arr.begin(), pge_arr.end());
    return pge_arr;
}

vector<int> pse(vector<int>& nums){
    // reverese nums // find nse_arr // pse_arr = rev of nse_arr
    reverse(nums.begin(), nums.end());

    vector<int> pse_arr(nums.size(), -1);
    stack<int> st; // to store index of nums
    st.push(0);
    for(int i=1;i<nums.size();i++){
        while(!st.empty() && nums[i]<nums[st.top()]){
            pse_arr[st.top()]= nums[i];
            st.pop();
        }
        st.push(i);
    }
    
    reverse(pse_arr.begin(), pse_arr.end());
    return pse_arr;
}

int main(){

    vector<int> nums= {4,6,3,1,0,9,5,6,7,3,2};
    vector<int> nge_arr= nge(nums);
    vector<int> nse_arr= nse(nums);
    for(int ele: nge_arr) cout<< ele<< " ";
    cout<< endl;
    for(int ele: nse_arr) cout<< ele<< " ";

return 0;    
}