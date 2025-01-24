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

class DSU{
private:
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
    }

    void make(int v){
        parent[v]= v;
        size[v]= 1;
    }

    int find(int v){
        if(parent[v]==v) return v;
        return parent[v]= find(parent[v]);
    }

    void union_(int a, int b){
        a= find(a);
        b= find(b);
        if(a==b) return;
        if(size[a]<size[b]) swap(a, b);
        parent[b]= a;
        size[a]+= size[b];
    }
};

class Graph{
private:
    int vert;
    int edge;
    vector<pair<int, pair<int, int>>> graph;
    DSU dsu;
public:
    Graph(int v, int e) : vert(v), edge(e), dsu(v) {
        graph.resize(edge);
    }

    int kruskal(){
        int mstSum= 0;
        cout<< "Enter connected nodes with the weight: "<< endl;
        for(int i=0;i<edge;i++){
            int v1, v2, wt;
            cin>> v1>> v2>> wt;
            graph.push_back({wt, {v1, v2}});
            // make v1, v2 as independent groups 
            dsu.make(v1), dsu.make(v2);
        }

        sort(graph.begin(), graph.end());
        for(int i=0;i<graph.size();i++){
            int edgwt= graph[i].first;
            int v1= graph[i].second.first, v2= graph[i].second.second;
            // if v1 and v2 have the same root/part of the same tree then connecting a edge between them will lead to the formation of a loop
            if(dsu.find(v1)==dsu.find(v2)) continue;

            mstSum+= edgwt;
            cout<< v1<< " "<< v2<< endl;
            dsu.union_(v1, v2);
        }
        return mstSum;
    }

};

int main(){

    Graph gph(6, 9);
    cout<< gph.kruskal();

return 0;    
}