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

int lca(vector<vector<int>> v, int v1, int v2)
{
    if(v1==1 || v2==1) return 1;
    if(v[v1][0]==v[v2][0]) return v[v1][0];
    if(v[v1][0]==v2) return v2;
    if(v[v2][0]==v1) return v1;
    
   return lca(v, v[v1][0], v[v2][0]);
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
    cout<< "Enter two vertices:\n";
    int v1, v2;
    cin>>v1>>v2;
    cout<< "LCA is: "<< lca(v, v1, v2);

return 0;    
}
