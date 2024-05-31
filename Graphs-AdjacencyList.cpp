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
public:
    Graph(int v, int e){
        vert= v, edge= e;
        graph.resize(vert+1);
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
};

int main(){



return 0;    
}