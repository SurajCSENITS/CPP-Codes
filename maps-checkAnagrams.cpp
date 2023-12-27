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

bool isAnagram(string str1, string str2)
{// anagram contains the same characters only the order is different
    if(str1.length()!=str2.length()) return false;

    map<char, int> m1;
    map<char, int> m2;

    for(char c: str1){
        if(m1.find(c)!=m1.end()){
            m1[c]+=1;
            continue;
        }
        m1[c]= 1;
    }
    for(char c: str2){
        if(m2.find(c)!=m2.end()){
            m2[c]+=1;
            continue;
        }
        m2[c]= 1;
    }
    // check if frequency of each char in both of the strings is equal
    for(auto pair: m1){
        if(m1[pair.first]!=m2[pair.first]) return false;
        if(m1[pair.second]!=m1[pair.second]) return false;
    }
    return true;
}

int main(){

    string str1= "triangle";
    string str2= "integral";
    cout<< isAnagram(str1, str2);

return 0;    
}
