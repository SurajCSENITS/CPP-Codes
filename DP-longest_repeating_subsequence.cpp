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


pair<string, int> longest_repeating_subsequence(string s){
    vector<vector<int>> dp(s.length()+1);
    for(auto& row: dp) row.resize(s.length()+1, 0);
    int m= dp.size();
    int n= dp[0].size();

    for(int i=1;i<m;i++){ // at any instant the lrs upto the length i,j will be in dp[i][j]
        for(int j=1;j<n;j++){
            if(s[i-1]==s[j-1] and i!=j) dp[i][j]= dp[i-1][j-1]+1;
            else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // back tracking
    string lrs= "";
    int i= m-1, j= n-1;
    while(i>0 and j>0){
        if(dp[i][j]>max(dp[i-1][j], dp[i][j-1])){
            lrs= s[i-1]+lrs;
            i= i-1;
            j= j-1;
        }
        else if(dp[i][j-1]>dp[i-1][j]) j= j-1;
        else i= i-1;
    }

    return make_pair(lrs, dp[m-1][n-1]);
}

int main(){

    string s= "AAPDRCDBBT";
    pair<string, int> lrs= longest_repeating_subsequence(s);
    cout<< lrs.first<<" "<< lrs.second;

return 0;    
}
