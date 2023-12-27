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

bool isIsomorphic(string s1, string s2){
    map<char, char> m;
    if(s1.length()!=s2.length()) return false;

    for(int i=0;i<s1.length();i++){ // s1 -> s2
        if(m.find(s1[i])!=m.end()){
            if(m[s1[i]]!=s2[i]) return false;
            continue;
        }
        m[s1[i]]= s2[i];
    }
    m.clear();
    for(int i=0;i<s2.length();i++){ // s2 -> s1
        if(m.find(s2[i])!=m.end()){
            if(m[s2[i]]!=s1[i]) return false;
            continue;
        }
        m[s2[i]]= s1[i];
    }
    
    return true;
}

int main(){

    string s1= "abcdec";
    string s2= "viouog";
    cout<< isIsomorphic(s1, s2);

return 0;    
}
