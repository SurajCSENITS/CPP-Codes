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


int leastInterval(vector<char>& tasks, int n){ // https://youtu.be/VGpamsI5hOM
    map<char, int> mp;
    for(char t: tasks){
        if(mp.count(t)==0) mp[t]= 1;
        else mp[t]+= 1;
    }

    priority_queue<int> pq;
    for(auto pair: mp) pq.push(pair.second);
    queue<pair<int, int>> q; // to handle the halt state
    int time= 0;
    int k= tasks.size();
    while(k>0){
        if(!q.empty() and time-q.front().second>n){
            pq.push(q.front().first);
            q.pop();
        }
        if(!pq.empty()){
            k--; // task executed
            if(pq.top()-1!=0) q.push({pq.top()-1, time});
            pq.pop();
        }
        time++;
    }
    return time;
}


int main(){



return 0;    
}
