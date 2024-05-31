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
    vector<vector<int>> graph;
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
            int v1, v2;
            cin>> v1>> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
    }

    void bfs(int root= 1){
        // For equal weighted graphs, level gives the shorest distance of each node from the root
        queue<int> q;
        vector<int> level(vert+1, 0);
        q.push(root); isVisited[root]= true;
        while(not q.empty()){
            cout<< q.front()<< " ";
            for(int child: graph[q.front()]) if(not isVisited[child]) q.push(child), level[child]= level[q.front()]+1, isVisited[child]= true;
            q.pop();
        }
    }
};

int main(){

    Graph gph(13, 12);
    gph.adjacencyList();
    gph.bfs(1);

return 0;    
}