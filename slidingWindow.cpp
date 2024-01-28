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


vector<int> slidingWindow(vector<int>& v, int k){
    int i= 0;
    deque<int> dq; // storing the index
    vector<int> maxV;

    // first k insertions in the window
    while(i<k){
        if(i==0) dq.push_back(i);
        else{
            while(!dq.empty() && v[i]>=v[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        i++;
    }
    maxV.push_back(v[dq.front()]);
    // rest of the insertions
    for(i;i<v.size();i++){
        if(i-k==dq.front()) dq.pop_front();
        while(!dq.empty() && v[i]>=v[dq.back()]) dq.pop_back();
        dq.push_back(i);
        maxV.push_back(v[dq.front()]);
    }
    return maxV;
}

int main(){

    vector<int> v= {4,1,3,5,1,2,3,2,1,1,5};
    int k;
    cin>> k;
    vector<int> maxV= slidingWindow(v, k);
    for(int ele: maxV) cout<< ele<< " ";

return 0;    
}
