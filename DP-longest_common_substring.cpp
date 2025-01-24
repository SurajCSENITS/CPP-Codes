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
#include <tuple>
#include <bits/stdc++.h>  

int util(string& a, string& b, unordered_map<string, int>& dp, int la, int lb, int count){ // https://www.youtube.com/watch?v=NvmJBCn4eQI
    if(la>=a.length() or lb>=b.length()) return count;

    string key= to_string(la)+"-"+to_string(lb)+"-"+to_string(count);
    if(dp.count(key)!=0) return dp[key];
    
    int same= count, diff1= 0, diff2= 0;
    if(a[la]==b[lb]){
        same= util(a, b, dp, la+1, lb+1, count+1);
    } else{
        diff1= util(a, b, dp, la, lb+1, 0);
        diff2= util(a, b, dp, la+1, lb, 0);
    }

    int res= max(same, max(diff1, diff2));
    return dp[key]= res;
}

int lcs(string a, string b){
    unordered_map<string, int> dp;
    return util(a, b, dp, 0, 0, 0);
}

int main(){

    string a= "pban";
    string b= "pcan";
    cout<< lcs(a, b);

return 0;    
}
