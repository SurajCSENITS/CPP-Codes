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


int findLHS(vector<int>& nums){ // Longest Harmonious Subsequence 594
    sort(nums.begin(), nums.end());
    int n= nums.size();
    int len= 0;
    for(int i=0;i<n-1;i++){
        if(i!=0 && nums[i]==nums[i-1]) continue;
        stack<int> st;
        st.push(nums[i]);
        for(int j=i+1;j<n;j++){
            if(nums[j]-nums[i]==0 || nums[j]-nums[i]==1) st.push(nums[j]);
            else break;
        }
        if(st.top()-nums[i]==1) len= max(len, static_cast<int>(st.size()));
    }
    return len;
}


int main(){

    vector<int> nums= {1,3,2,2,5,2,3,7};
    cout<< findLHS(nums);


return 0;    
}
