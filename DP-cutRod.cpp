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


int cutRod(int length, vector<int>& profit, vector<int>& dp){
    if(length==0) return 0;
    if(dp[length]!=0) return dp[length];

    int maxProfit= 0;
    for(int i=1;i<=length;i++){
        int currProfit= profit[i];
        currProfit+= cutRod(length-i, profit, dp);
        maxProfit= max(maxProfit, currProfit);
    }

    dp[length]= maxProfit;
    return maxProfit;
}

// without reccurrsion
int cutRodII(int length, vector<int>& profit){
    if(length==0) return 0;

    vector<int>  dp(length+1, 0);
    for(int i=1;i<=length;i++){
        for(int j=1;j<=i;j++){ // from the ith length we are cutting the jth length
            int currProfit= profit[j]+dp[i-j];
            dp[i]= max(dp[i], currProfit);
        }
    }

    return dp[length];
}

int main(){

    int length= 8;
    vector<int> profit= {0,1,5,6,9,11,12,14,16};
    vector<int> dp(length+1, 0);
    cout<< cutRod(length, profit, dp);
    cout<< endl;
    cout<< cutRodII(length, profit);

return 0;    
}
