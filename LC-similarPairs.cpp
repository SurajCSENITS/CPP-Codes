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

int similarPairs(vector<string>& words){
        int count= 0;
        vector<unordered_set<char>> v(words.size());
        // inserting into vectors
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++) 
                v[i].insert(words[i][j]);
        }
        // check for equal vector sets
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                bool flag= true;
                if(v[i].size()!=v[j].size()) continue;
                for(auto ele: v[i]){
                    if(v[j].find(ele)==v[j].end()){ 
                        flag= false;
                        break;
                    }
                }
                if(flag) count++;
            }
        }
        return count;
    }
// ["nba","cba","dba"]


int main(){

    vector<string> words= {"nba", "cba", "dba"};
    cout<< similarPairs(words);

return 0;    
}
