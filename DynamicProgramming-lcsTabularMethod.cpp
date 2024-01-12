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

// DynamicProgramming
pair<string, int> lcsTabularMethod(string s1, string s2){
    vector<vector<int>> dp(s1.length()+1);
    for(auto& row: dp) row.resize(s2.length()+1, 0);
    int m= dp.size();
    int n= dp[0].size();

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){ // at any instant the lcs upto the length i,j will be in dp[i][j]
            if(s1[i-1]==s2[j-1]) dp[i][j]= dp[i-1][j-1]+1;
            else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // back tracking
    string lcs= "";
    int i= m-1, j= n-1;
    while(i>0 and j>0){
        if(dp[i][j]>max(dp[i-1][j], dp[i][j-1])){
            lcs= s1[i-1]+lcs;
            i= i-1;
            j= j-1;
        }
        else if(dp[i][j-1]>dp[i-1][j]) j= j-1;
        else i= i-1;
    }

    return make_pair(lcs, dp[m-1][n-1]);
}

int main(){

    string s1= "ABCAB";
    string s2= "AECB";
    pair<string, int> lcs= lcsTabularMethod(s1, s2);
    cout<< lcs.first<<" "<< lcs.second;

return 0;    
}
