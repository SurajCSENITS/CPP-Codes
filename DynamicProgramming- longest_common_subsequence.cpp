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

int longest_common_subsequence(string s1, string s2, vector<vector<int>>& dp){
    // Base case
    if(s1.length()==0 || s2.length()==0) return 0;
    // when dp works    
    if(dp[s1.length()-1][s2.length()-1]!=-1) return dp[s1.length()-1][s2.length()-1];

    if(s1.back()==s2.back()){
        s1.pop_back();
        s2.pop_back();

        dp[s1.length()-1][s2.length()-1]= longest_common_subsequence(s1, s2, dp);
        return 1+dp[s1.length()-1][s2.length()-1];
    }
    // else
    char temp= s2.back();
    s2.pop_back();
    int l1= longest_common_subsequence(s1, s2, dp);
    dp[s1.length()-1][s2.length()-1]= l1;
    s2= s2+temp;

    temp= s1.back();
    s1.pop_back();
    int l2= longest_common_subsequence(s1, s2, dp);
    dp[s1.length()-1][s2.length()-1]= l2;
    s1= s1+temp;

    dp[s1.length()-1][s2.length()-1]= max(l1, l2);
    return max(l1, l2);
}


int main(){

    string s1= "ABCAB";
    string s2= "AECB";
    vector<vector<int>> dp(s1.length());
    for(auto& row: dp) row.resize(s2.length(), -1);

    cout<< longest_common_subsequence(s1, s2, dp);

return 0;    
}
