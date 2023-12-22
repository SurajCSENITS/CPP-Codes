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

// m_d_n -> maxm dept wala node
// m_d -> maxm dept 

void dfsTree(vector<vector<int>> v, int vertex, int* m_d_n, vector<int> dept, int* m_d, int par= 0){
    for(int child: v[vertex]){
        if(child==par) continue;
        dept[child]= dept[vertex]+1;
        if(dept[child]>*m_d){
            *m_d= dept[child];
            *m_d_n= child;
        } 
        dfsTree(v, child, m_d_n, dept, m_d, vertex);
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
    
    // first find m_d_n wrt any vertex
    int m_d_n;
    int m_d= 0;
    vector<int> dept(vert+1, 0);
    dfsTree(v, 1, &m_d_n, dept, &m_d);

    // then find the m_d wrt this m_d_n
    m_d= 0;
    dfsTree(v, m_d_n, &m_d_n, dept, &m_d);
    cout<< "Diameter of tree: "<< m_d;

return 0;    
}
