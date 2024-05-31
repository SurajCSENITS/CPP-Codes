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

    void dfs(int vertex){
        if(isVisited[vertex]) return;

        // process curr vertex
        isVisited[vertex]= true;
        // cout<< vertex<< " ";
        for(int child: graph[vertex]) dfs(child);
    }

    int connectedComponents(){
        int count= 0;
        for(int vertex=1;vertex<=vert;vertex++){
            if(isVisited[vertex]) continue;
            count++;
            dfs(vertex);
        }
        return count;
    }

    bool helper(int vertex, int parent= -1){
        isVisited[vertex]= true;
        for(int child: graph[vertex]){
            if(isVisited[child] and child!=parent) return true;
            if(isVisited[child]) continue;
            if(helper(child, vertex)) return true;
        }
        return false;
    }

    bool isCyclic(){
        // There can be more than 1 connected components
        bool doesLoopExist= false;
        for(int v=1;v<=vert;v++){
            if(isVisited[v]) continue;
            doesLoopExist|= helper(v);
            if(doesLoopExist) break;
        }
        return doesLoopExist;
    }
};

int main(){

    Graph gph(8, 6);
    gph.adjacencyList();
    cout<< gph.isCyclic();

return 0;    
}