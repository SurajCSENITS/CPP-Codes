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

int maxProfit(int capacity, vector<int>& weight, vector<int>& price, vector<vector<int>>& dp, int value= 0, int i= 0){ // capacity -> remaining weight capacity
    if(capacity==0) return value;

    if(i<weight.size()){
        if(dp[capacity][i]!=-1) value= dp[capacity][i];      
        else{
            int v1= -1;
            if(capacity-weight[i]>=0) v1= maxProfit(capacity-weight[i], weight, price, dp, value+price[i], i+1); // if we take weight[i]
            int v2= maxProfit(capacity, weight, price, dp, value, i+1); // if we not take weight[i]
            value= max(v1, v2);
        }
    }

    dp[capacity][i]= value;
    return value;
}


int main(){

    int capacity= 10;
    vector<int> weight= {1,3,4,6};
    vector<int> price= {20,30,10,50};
    vector<vector<int>> dp(capacity+1);
    for(int i=0;i<dp.size();i++) dp[i].resize(weight.size(), -1);
    cout<< maxProfit(capacity, weight, price, dp);

return 0;    
}
