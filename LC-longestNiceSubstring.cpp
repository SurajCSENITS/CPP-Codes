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

int ifNice(string s, int l, int r){
    bool flag= true;
    for(int i=l;i<=r;i++){
        for(int j=l;j<=r;j++){
            if(abs(s[i]-s[j])==32){
                flag= false;
                break;
            }
        }
        if(flag) return i;
        flag= true;
    }
    return -1;
}

string divide_and_conquer(string s, int l, int r){
    if(l>=r) return "";
    int probIdx= ifNice(s, l, r);
    if(probIdx==-1){
         return s.substr(l, r-l+1);
    }
    string s1= divide_and_conquer(s, l, probIdx-1);
    string s2= divide_and_conquer(s, probIdx+1, r);
    if(s1.size()>s2.size()) return s1;
    return s2;
}

string longestNiceSubstring(string s){
    string ans= divide_and_conquer(s, 0, s.length()-1);
    return ans;
}

int main(){

    string s= "YazaAay";
    cout<< longestNiceSubstring(s);

return 0;    
}
