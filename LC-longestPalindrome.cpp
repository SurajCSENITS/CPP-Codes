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

string longestPalindrome(string s){ // O(n)
    // stop when lo, hi go out of range or when s[lo]!=s[hi]
    string lps= "";
    for(int i=0;i<s.length()-1;i++){
        // odd length palindrome
        string temp= "";
        int lo= i, hi= i;
        while(lo>=0 and hi<s.size() and s[lo]==s[hi]){
            if(lo==hi) temp+= s[lo];
            else temp= s[lo]+temp+s[hi];
        }
        if(temp.length()>lps.length()) lps= temp;

        // even length palindrome
        lo= i, hi= i+1;
        temp.clear();
        while(lo>=0 and hi<s.size() and s[lo]==s[hi]) temp= s[lo--]+temp+s[hi++];
        if(temp.length()>lps.length()) lps= temp;
    }

    return lps;
}


int main(){

    string s= "babad";
    cout<< longestPalindrome(s);


return 0;    
}
