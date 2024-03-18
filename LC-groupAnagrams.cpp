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

vector<vector<string>> groupAnagrams(vector<string>& strs){
    // after sorting all anagrams become equal strings
    unordered_map<string, vector<string>> mp;
    for(int i=0;i<strs.size();i++){ // O(n)
        string key= strs[i];
        sort(key.begin(), key.end());
        mp[key].push_back(strs[i]); 
    }
    // insert into 2D VECTOR
    vector<vector<string>> anagrams;
    for(unordered_map<string, vector<string>>:: iterator itr= mp.begin();itr!=mp.end();itr++)
        anagrams.push_back(itr->second);
    return anagrams;
}

int main(){

    vector<string> strs= {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> anagrams= groupAnagrams(strs);
    for(auto& row: anagrams){
        for(auto& str: row) cout<< str<< " ";
        cout<< endl;
    }


return 0;    
}