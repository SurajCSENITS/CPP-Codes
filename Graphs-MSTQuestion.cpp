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
        if(a<b) swap(a, b);
        parent[b]= a;
        size[a]+= size[b];
    }
};

void electrify(int n, vector<int> x, vector<int> y, vector<int> c, vector<int> k){
    vector<pair<int, pair<int, int>>> graph;
    // connect all the cities
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            int connectionCost= (k[i-1]+k[j-1]) * (abs(x[i-1]-x[j-1]) + abs(y[i-1]-y[j-1]));
            graph.push_back({connectionCost, {i, j}});
        }
    }
    // also connect with 0th vertex to represent the ps building cost 
    for(int i=1;i<=n;i++){
        int edgwt= c[i-1];
        graph.push_back({edgwt, {0, i}});
    }
    // apply kruskal to find the mstSum which is min cost to electrify the cities
    DSU dsu(n);
    for(int i=0;i<=n;i++) dsu.make(i);
    int minCost= 0;
    vector<int> powerStations; 
    sort(graph.begin(), graph.end());
    for(int i=0;i<graph.size();i++){
        int edgwt= graph[i].first;
        int v1= graph[i].second.first;
        int v2= graph[i].second.second;
        if(dsu.find(v1)==dsu.find(v2)) continue;

        minCost+= edgwt;
        if(v1==0) powerStations.push_back(v2);
        else cout<< v1<< " "<< v2<< endl;
        dsu.union_(v1, v2);
    }
    cout<< "Min Cost: "<< minCost<< endl;
    cout<< "Power Staions: ";
    for(int i=0;i<powerStations.size();i++) cout<< powerStations[i]<< " ";
}

int main(){

    int n= 3;
    vector<int> x= {2,1,3}, y= {3,1,2};
    vector<int> c= {3,2,3};
    vector<int> k= {3,2,3};
    electrify(n, x, y, c, k);

return 0;    
}