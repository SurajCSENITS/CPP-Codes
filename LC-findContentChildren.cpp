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

int findContentChildren(vector<int>& g, vector<int>& s){
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int j= 0;
    int count= 0;
    for(int i=0;i<g.size();i++){
        for(j;j<s.size();j++){
            if(s[j]>=g[i]){
                count++;
                j++;
                break;
            }
        }
        if(j==s.size()) break;
    }
    return count;
}

int main(){

    vector<int> g= {1,2,3};
    vector<int> s= {1,1};
    cout<< findContentChildren(g, s);

return 0;    
}
