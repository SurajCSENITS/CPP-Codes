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


int firstUniqChar(string s){
    vector<int> freq(26, 0);
    for(int i=0;i<s.length();i++) freq[s[i]-'a']++;
    for(int i=0;i<s.length();i++) if(freq[s[i]-'a']==1) return i;
    return -1;
}

int main(){

    string str= "leetcode";
    cout<< firstUniqChar(str);

return 0;    
}