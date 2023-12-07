#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>

int** createGraph(int v, int e)
{
    // create an adjacency matrix of VxV
    // Allocate memory for v rows of int*
    int** adj = new int*[v];
    // Allocate memory for each row
    for (int i = 0; i < v; ++i) {
        adj[i] = new int[v];
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            adj[i][j]= 0;
        }
    }

    cout<<"Enter adjacent vertices(a pair should be entered only once, irrespective of its order)"<<endl;
    for(int i=0;i<e;i++){// no. of traversals = no. of edges
        int a, b;
        cin>>a>>b;
        adj[a][b]= 1;
        adj[b][a]= 1;
    }

    return adj;

}

int main(){

    int v, e;
    cin>>v;
    cin>>e;
    int** graph= createGraph(v, e);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            cout<< graph[i][j]<<" ";
        cout<< endl;
    }

return 0;    
}