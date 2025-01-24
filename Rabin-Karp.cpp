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
#include <tuple>
#include <bits/stdc++.h>

class Solution { // leetcode 1044 https://youtu.be/FQ8hcOOzQMU
private:
    const int prime= 10000001;
public:
    string longestDupSubstring(string s){
        // initially l= 1, h= s.length(), mid= (l+h)/2
        // make a sliding window of size `mid`
        // enter hash value of all substrings of length `mid` into the map
        // if any hash value matches then check whether the strings are equal or not
        // if equal, update candidate and l= mid+1
        // else r= mid-1

        // precompute the powers of 26
        int n= s.length();
        vector<int> power(n, 0);
        power[0]= 1;
        for(int i=1;i<n;i++) power[i]= (power[i-1]*26)%prime;

        int l= 1;
        int h= n;
        string candidate= "";
        while(l<=h){
            int mid= (l+h)/2;
            int hash= 0, i= 0, j= -1;
            unordered_map<int, vector<int>> hash_map;
            while(j-i+1<mid){
                j+= 1;
                hash= ((hash*26)%prime + (s[j]-'a'))%prime;
            }
            hash_map[hash].push_back(i);

            while(j<n-1){
                hash= hash - (s[i++]-'a')*power[mid-1];
                hash= ((1LL*hash*26)%prime + (s[++j]-'a') + prime)%prime;
                
                if(hash_map.count(hash)!=0){
                    for(int start: hash_map[hash]){
                        if(s.substr(i, j-i+1)==s.substr(start, mid)){
                            candidate= s.substr(i, j-i+1);
                            l= mid+1;
                            break;
                        }
                    }
                } 
                hash_map[hash].push_back(i);

                if(l==mid+1) break;
            }
            
            if(l!=mid+1) h= mid-1;
        }
        return candidate;
    }
};