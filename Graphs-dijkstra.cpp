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
            graph[v1].push_back({v2, wt});
        }
    }

    vector<int> dijkstra(int source= 1){
        set<pair<int, int>> st; // dist - node
        vector<int> distance(vert+1, INT32_MAX);
        st.insert({0, source});
        while(!st.empty()){
            int curr_node= (*st.begin()).second;
            st.erase(st.begin());
            if(isVisited[curr_node]) continue;
            
            for(pair<int, int> child: graph[curr_node]){
                int childV= child.first;
                int edWt= child.second;
                if(distance[curr_node]+edWt<distance[childV]) st.insert({distance[curr_node]+edWt, childV}), distance[childV]= distance[curr_node]+edWt;
            }
            isVisited[curr_node]= true;
        }
        return distance;
    }
    
};

int main(){

    Graph g(13, 12);
    g.adjacencyList();


return 0;    
}