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

int minCoins(int rupee, vector<int>& coins, vector<int>& dp){ // YT channel -> "Anuj Bhaiya"
    if(rupee==0) return dp[0]= 0;

    int ans= INT32_MAX;
    for(int i=0;i<coins.size();i++){
        if(rupee-coins[i]<0) continue;
        int subAns= 0;
        if(dp[rupee-coins[i]]!=-1) subAns= dp[rupee-coins[i]];
        else subAns= minCoins(rupee-coins[i], coins, dp);
        if(subAns+1<ans) ans= subAns+1; // +1 -> coin is coins[i]
    }

    dp[rupee]= ans;
    return ans;
}

int main(){

    int rupee;
    cin>> rupee;
    vector<int> coins= {7,5,1};
    vector<int> dp(rupee+1, -1); // stores the precalculated values
    cout<< minCoins(rupee, coins, dp)<< " ";
    for(int i=0;i<dp.size();i++) cout<< dp[i]<< " ";

return 0;    
}
