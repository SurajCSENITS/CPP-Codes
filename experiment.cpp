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


vector<int> nge_idx(vector<int>& nums){
    // increasing and decreasing curve approach
    vector<int> nge(nums.size(), -1);
    stack<int> st; // to store index of nums
    st.push(0);
    for(int i=1;i<nums.size();i++){
        while(!st.empty() && nums[i]>nums[st.top()]){
            nge[st.top()]= i;
            st.pop();
        }
        st.push(i);
    }
    return nge;
}

vector<int> dailyTemperatures(vector<int>& temperatures){
    // number of days = nge_idx - curr_idx
    vector<int> nge= nge_idx(temperatures);
    vector<int> answer(temperatures.size(), 0);
    for(int i=0;i<temperatures.size();i++){
        if(nge[i]==-1) continue; // if nge does not exist
        answer[i]= nge[i]-i;
    }
    return answer;
}

int main(){

    vector<int> temperatures= {73,74,75,71,69,72,76,73};
    vector<int> answer= dailyTemperatures(temperatures);
    for(int ele: answer) cout<< ele<<" ";

return 0;    
}