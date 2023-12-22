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

void dfsTree(vector<vector<int>> v, int vertex, int par= 0){
    for(int child: v[vertex]){
        if(child==par) continue;
        dfsTree(v, child, vertex);
    }
}

int main(){

    int vert= 13;
    int edge= 12;
    vector<vector<int>> v; 
    v.resize(vert+1);
    cout<<"Enter adjacent vertices(a pair should be entered only once, irrespective of its order)"<<endl;
    for(int i=0;i<edge;i++){
        int v1, v2;
        cin>>v1>>v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    dfsTree(v, 1);

return 0;    
}
