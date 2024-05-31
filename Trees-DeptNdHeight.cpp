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
/* 
i/ps:
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
4 9
4 10
8 12
10 11
*/

class Tree{
private:
    int vert;
    int edge;
    vector<vector<int>> tree;
    vector<bool> isVisited;
public:
    Tree(int v, int e){
        vert= v, edge= e;
        tree.resize(vert+1);
        isVisited.resize(vert+1, false);
    }

    void adjacencyList(){
        cout<< "Enter Connected Nodes: "<< endl;
        for(int i=0;i<edge;i++){
            int v1, v2;
            cin>> v1>> v2;
            tree[v1].push_back(v2);
            tree[v2].push_back(v1);
        }
    }

    void dfs(int vertex){
        if(isVisited[vertex]) return;

        // process curr vertex
        isVisited[vertex]= true;
        // cout<< vertex<< " ";
        for(int child: tree[vertex]) dfs(child);
    }

    int connectedComponents(){
        int count= 0;
        for(int vertex=1;vertex<=vert;vertex++){
            if(isVisited[vertex]) continue;
            count++;
            dfs(vertex);
        }
        return count;
    }

    void depthNheightUtil(vector<int>& depth, vector<int>& height, int vertex= 1){
        // d(child)=d(par)+1 | h(par)=max(h(children))+1
        isVisited[vertex]= true;
        for(int child: tree[vertex]){
            if(isVisited[child]) continue; // ***
            depth[child]= depth[vertex]+1;
            depthNheightUtil(depth, height, child);
            height[vertex]= max(height[vertex], height[child]+1);
        }
    }

    pair<vector<int>, vector<int>> getDepthNdHeight(){
        vector<int> depth(vert+1, 0), height(vert+1, 0);
        depthNheightUtil(depth, height);
        return make_pair(depth, height);
    }
};

int main(){

    Tree t(13, 12);
    t.adjacencyList();
    pair<vector<int>, vector<int>> info= t.getDepthNdHeight();
    for(int d: info.first) cout<< d<< " ";
    cout<< endl;
    for(int h: info.second) cout<< h<< " ";
    cout<< endl;

return 0;    
}