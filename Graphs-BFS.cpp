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

void bfs(vector<vector<int>> v, queue<int>* qu, vector<bool>& visited, int i, vector<int>& level) // breadth first search
{
    cout<< i<< " : "<< level[i]<< endl;
    visited[i]= true; qu->pop();
    
    for(int child: v[i]){
        if(visited[child]) continue;
        qu->push(child);
        level[child]= level[i]+1;
    }

   if(!qu->empty()) bfs(v, qu, visited, qu->front(), level);
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
   
   queue<int> qu; qu.push(1);
   vector<bool> visited(vert+1, false);
   vector<int> level(vert+1, 0);
   bfs(v, &qu, visited, 1, level); // it is a kind of level order traversal, the level is calculated by the no. of edges betn the particular node and the root node, IN OTHER WORDS THE LEVEL OF A NODE IS ITS DISTANCE FROM THE ROOT NODE


return 0;    
}
