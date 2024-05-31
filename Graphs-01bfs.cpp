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

// Note: 'v' num of vertices => nodes val lies betn 1 to 'v'

class Graph{
private:
    int vert;
    int edge;
    vector<vector<pair<int, int>>> graph;
    vector<bool> isVisited;
public:
    Graph(int v, int e){
        vert= v, edge= e;
        graph.resize(vert+1);
        isVisited.resize(vert+1, false);
    }

    void adjacencyList(){
        cout<< "Enter Connected Nodes: "<< endl;
        for(int i=0;i<edge;i++){
            int v1, v2, wt;
            cin>> v1>> v2;
            if(v1==v2) continue;
            // add a edge betn v1 and v2(directed graph) with wt of 0
            graph[v1].push_back({v2, 0});
            // add a reverse edge with wt 1
            graph[v2].push_back({v1, 1});
        }
    }

    int minEdgesToReverse(int src, int dest){
        deque<int> dq;
        vector<int> level(vert+1, INT32_MAX);
        dq.push_back(src);
        isVisited[src]= true;
        level[src]= 0;

        while(!dq.empty()){
            int curr_vert= dq.front();
            dq.pop_front();
            for(pair<int, int> child: graph[curr_vert]){
                int v= child.first;
                int wt= child.second;
                if(level[curr_vert]+wt<level[v]) level[v]= level[curr_vert]+wt;
                else continue;
                if(wt==0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
        return level[dest];
    }

};

int main(){

    

return 0;    
}