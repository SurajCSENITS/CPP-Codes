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


int search(vector<int>& v, int target, int strt_idx){
    for(int i=strt_idx;i<v.size();i++) if(v[i]==target) return i;
    return -1;
}

bool closeStrings(string word1, string word2){
    // concept : No. of each char in both the words should be same
    // create two vectors to store the freq of each char in w1 and w2
    vector<int> freq1(26, 0), freq2(26, 0);
    for(char ch: word1) freq1[ch-'a']+= 1;
    for(char ch: word2) freq2[ch-'a']+= 1;

    for(int i=0;i<freq1.size();i++){
        if(freq1[i]==freq2[i]) continue;
        if((freq1[i]!=0 and freq2[i]==0) or (freq1[i]==0 and freq2[i]!=0)) return false;

        int idx= search(freq1, freq2[i], i+1); // searches freq2[i] element into freq1 vec from idx i+1
        if(idx==-1) return false;
        swap(freq1[i], freq1[idx]);
    }
    return true;
}

int main(){



return 0;
}