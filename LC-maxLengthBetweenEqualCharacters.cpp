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

int maxLengthBetweenEqualCharacters(string s){
    stack<char> st;
    int ans= -1;
    for(int i= 0;i<s.length()-1;i++){
        for(int j=i+1;j<s.length();j++){
            if(s[j]==s[i]){
                int s= st.size();
                ans= max(ans, s);
            }
            st.push(s[j]);
        }
        while(!st.empty()) st.pop();
    }
    return ans;
}

int main(){

    
    
return 0;    
}
