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

    void make(int v){ // adds an independent node
        parent[v]= v;
        size[v]= 1;
    }

    int find(int v){// returns the root of v
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

    int getGroupsCount(){
        int connectedComponents= 0;
        for(int v=1;v<parent.size();v++) if(parent[v]==v) connectedComponents++;
        return connectedComponents;
    }
};

int main(){

    int n, k;
    cin>> n>> k;
    DSU dsu(n);
    for(int i=1;i<=n;i++) dsu.make(i);
    while(k--){
        int u, v;
        cin>> u>> v;
        dsu.union_(u, v);
    }

    cout<< dsu.getGroupsCount();

return 0;    
}