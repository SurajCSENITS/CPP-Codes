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

int primsAlgorithm(vector<vector<pair<int, int>>>& graph, int n){
    vector<bool> isVisited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mstSum= 0;

    pq.push({0, 0});
    while(!pq.empty()){
        int dist= pq.top().first;
        int node= pq.top().second;
        pq.pop();
        if(isVisited[node]) continue;

        mstSum+= dist;
        isVisited[node]= true;
        for(pair<int, int> p: graph[node]){
            int child= p.first;
            int edgWt= p.second;
            pq.push({dist+edgWt, child});
        }
    }
    return mstSum;
}

int main(){


return 0;
}