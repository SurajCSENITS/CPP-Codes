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


int findMaxLength(vector<int>& nums){ // https://youtu.be/agB1LyObUNE
    // prefix array map : storing the diff betn no. of 1s and 0s and the ending idx of the first prefix array having that diff
    map<int, int> mp;
    int one= 0, zero= 0;
    int maxlen= 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1) one++;
        else zero++;
        if(one==zero) maxlen= i+1;
        else{
            int diff= one-zero;
            if(mp.count(diff)==0) mp[diff]= i;
        }
    }

    for(int j=nums.size()-1;j>0;j--){
        if(one==zero) maxlen= max(maxlen, j+1);        
        else{
            int diff= one-zero;
            if(mp.count(diff)!=0) maxlen= max(maxlen, j-mp[diff]);
        }
        if(nums[j]==1) one--;
        else zero--;
    } 
    return maxlen;   
}

int main(){



return 0;    
}
