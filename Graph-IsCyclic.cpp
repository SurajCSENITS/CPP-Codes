#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include <bits/stdc++.h>

class Graph
{
public:
    int v;
    int e;
    vector<vector<int>> dynamic_2d_vector;
    bool* visited;

    Graph(int vert, int edge){
        v= vert;
        e= edge;
        dynamic_2d_vector.resize(v+1); // assuming 1 base indexing

        visited= new bool[v+1];
        for(int i=0;i<=v;i++)
            visited[i]= false;
    }
    void createGraphList(){
        cout<<"Enter adjacent vertices(a pair should be entered only once, irrespective of its order)"<<endl;
        for(int i=0;i<e;i++){// no. of traversals = no. of edges
            int v1, v2;
            cin>>v1>>v2;
            dynamic_2d_vector[v1].push_back(v2);
            dynamic_2d_vector[v2].push_back(v1);
        }
    }
    void display(){
        for(int i=1;i<=v;i++){
            cout<<i<<" ";
            for(int j=0;j<dynamic_2d_vector[i].size();j++)
                cout<<dynamic_2d_vector[i][j]<<" ";
            cout<< endl;
        }
    } 
    bool isCyclic(int vertex, int par) {
        visited[vertex]= true;
        bool isLoopExist= false;
        for(int child: dynamic_2d_vector[vertex]){
            if(visited[child] && child==par)
                continue;
            if(visited[child])
                return true;
            isLoopExist |= isCyclic(child, vertex);
        }

        return isLoopExist;
    } 
    void reintialiseVisited(){
        for(int i=0;i<=v;i++)
            visited[i]= false;
    }
};

bool isCyclePresent(Graph g)
{
    bool isLoopExist= false;
    for(int i=1;i<=g.v;i++){
        if(g.visited[i])
            continue;
        if(g.isCyclic(i, 0)){
            isLoopExist= true;
            break;
        }
    }
    
    return isLoopExist;
}

int main(){

    int v, e;
    cin>>v>>e;
    Graph g(v, e);
    g.createGraphList();
    g.display();

    cout<<isCyclePresent(g)<<endl;

return 0;    
}