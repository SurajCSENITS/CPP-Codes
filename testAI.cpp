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

class Solution {
public:
    int helper(string& s, vector<vector<int>>& freq, vector<bool>& takenAsEndPoint, int l, int r){
        if(l>r) return 0;
        if(s[l]==s[r]){
            if(takenAsEndPoint[s[l]]) return helper(s, freq, takenAsEndPoint, l+1, r-1);
            int countInBetn= 0;
            for(int i=0;i<26;i++)
                if(freq[r-1][i]-freq[l][i]) countInBetn++;
            takenAsEndPoint[s[l]]= true;
            return countInBetn+helper(s, freq, takenAsEndPoint, l+1, r-1);
        } else{
            
        }
    }

    int countPalindromicSubsequence(string s){
        int n= s.length();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        vector<bool> takenAsEndPoint(26, false);
        freq[0][s[0]-'a']= 1;
        for(int i=1;i<n;i++){
            freq[i]= freq[i-1];
            freq[i][s[i]-'a']++;
        }
        return helper(s, freq, takenAsEndPoint, 0, n-1);
    }
};

int main(){

return 0;
}