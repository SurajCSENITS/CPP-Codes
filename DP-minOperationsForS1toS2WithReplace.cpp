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


int minOperationsForS1toS2(string s1, string s2){
    // Base case if any one of the strings become empty
    if(s1.size()==0) return s2.length();
    if(s2.size()==0) return s1.length();

    if(s1.back()==s2.back()){
        s1.pop_back();
        s2.pop_back();
        return minOperationsForS1toS2(s1, s2);
    }

    char temp= s2.back(); s2.pop_back();
    int n1= 1 + minOperationsForS1toS2(s1, s2);

    s1.pop_back(); s2= s2+temp;
    int n2= 1 + minOperationsForS1toS2(s1, s2);

    s2.pop_back();
    int n3= 1 + minOperationsForS1toS2(s1, s2);
    return min(n1, min(n2, n3));
}

// Tabular Method: DP
int minOperationsDP(string s1, string s2){
    vector<vector<int>> dp(s1.length()+1);
    for(auto &raw: dp) raw.resize(s2.length()+1, -1);
    // fill first row and first column
    int fill= 0;
    for(int j=0;j<dp[0].size();j++) dp[0][j]= fill++;
    fill= 0;
    for(int i=0;i<dp.size();i++) dp[i][0]= fill++;

    int m= dp.size();
    int n= dp[0].size();
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]= dp[i-1][j-1];
            else dp[i][j]= 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }

    return dp[m-1][n-1];
}

int main(){

    string s1= "DOG";
    string s2= "DIG";
    cout<< minOperationsForS1toS2(s1, s2);

return 0;    
}
