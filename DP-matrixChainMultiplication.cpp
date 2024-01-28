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

int matrixChainMultiplication(vector<int>& v){ // v -> vector of dimensions
    int n= v.size();
    vector<vector<int>> dp(n);
    for(auto &row: dp) row.resize(n, 0);

    for(int len=2;len<n;len++){ // len= 2 *
        for(int row= 0, col= len; row<n-len; row++, col++){ // each diagonal iteration is starting from 0th row
            dp[row][col]= INT32_MAX;
            for(int k=row+1;k<col;k++){
                dp[row][col]= min(dp[row][col], dp[row][k]+dp[k][col]+v[row]*v[k]*v[col]);
            }
        }
    }
    return dp[0][n-1];
}

int main(){

    vector<int> v= {2,3,4,1,3};
    cout<< matrixChainMultiplication(v);

return 0;    
}
