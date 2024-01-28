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


int optimalBST(vector<int>& keys, vector<int>& freq){
    int n= keys.size();
    // create a dp table
    vector<vector<int>> dp(n);
    for(auto &row: dp) row.resize(n, 0);

    // calculate prefix freq sum
    vector<int> freqSum= freq;
    for(int i=1;i<n;i++) freqSum[i]+= freqSum[i-1];
    // fill dp
    for(int len=0;len<n;len++){
        for(int col=len, row=0;col<n;col++, row++){
            if(len==0) dp[row][col]= freq[col];
            else{
                dp[row][col]= INT32_MAX;
                int sum= row==0 ? freqSum[col] : freqSum[col]-freqSum[row-1];
                for(int k=row;k<=col;k++){
                    if(k==row) dp[row][col]= min(dp[row][col], dp[k+1][col]+sum);
                    else if(k==col) dp[row][col]= min(dp[row][col], dp[row][k-1]+sum);
                    else dp[row][col]= min(dp[row][col], dp[row][k-1]+dp[k+1][col]+sum);   
                }
            }
        }
    }

    return dp[0][n-1];
}

int main(){

    vector<int> keys= {10,20,30,40}; // sorted
    vector<int> freq= {3,1,2,1};
    cout<< optimalBST(keys, freq);

return 0;    
}
