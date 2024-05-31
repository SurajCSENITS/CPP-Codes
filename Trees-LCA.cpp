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

    void reset(){ for(int i=0;i<isVisited.size();i++) isVisited[i]= false; }
       
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

    void sumNcountUtil(vector<int>& subtreeSum, vector<int>& evenCount, int vertex= 1){
        isVisited[vertex]= true;
        subtreeSum[vertex]+= vertex;
        evenCount[vertex]+= vertex%2==0 ? 1 : 0;
        for(int child: tree[vertex]){
            if(isVisited[child]) continue;
            sumNcountUtil(subtreeSum, evenCount, child);
            subtreeSum[vertex]+= subtreeSum[child];
            evenCount[vertex]+= evenCount[child];
        }
    }

    pair<vector<int>, vector<int>> getSubtreeSumNdEvenCount(){
        vector<int> subtreeSum(vert+1, 0);
        vector<int> evenCount(vert+1, 0);
        sumNcountUtil(subtreeSum, evenCount);
        return make_pair(subtreeSum, evenCount);
    }

    int getMaxDepth(int vertex= 1){
        int maxDepth= 0;
        isVisited[vertex]= true;
        for(int child: tree[vertex]){
            if(isVisited[child]) continue;
            maxDepth= max(maxDepth, getMaxDepth(child)+1);
        }
        return maxDepth;
    }

    int diameter(){
        /*
        #trick to find diamter in a tree
            1. With any root find the maxm-depth-node
            2. With that node as root find the maxm depth, which is the diameter of the tree
        */ 
        vector<int> depth= getDepthNdHeight().first;
        int maxDepth= INT32_MIN, maxDepthNode;
        for(int node=1;node<=vert;node++) if(maxDepth<depth[node]) maxDepth= depth[node], maxDepthNode= node;     
        // Reset the isVisited array
        reset();
        int diameter= getMaxDepth(maxDepthNode);
        return diameter;
    }

    vector<int> getPath(int target, int vertex= 1){
        vector<int> path;
        isVisited[vertex]= true;
        if(target==vertex){
            path.push_back(vertex);
            return path;
        }

        for(int child: tree[vertex]){
            if(isVisited[child]) continue;
            vector<int> childToTarget= getPath(target, child);
            if(not childToTarget.empty()){
                path= childToTarget;
                path.insert(path.begin(), vertex);
                return path;
            }
        }
        return path;
    }   

    int lca(int node1, int node2){
        /*
            find the paths of two nodes from root
            from those two paths the farthest common node is the lca
        */
       vector<int> path1= getPath(node1);
       reset(); // reset isVisited
       vector<int> path2= getPath(node2);
       int lca= -1;
       for(int i=0;i<min(path1.size(), path2.size());i++){
            if(path1[i]!=path2[i]) return lca;
            lca= path1[i];
       }
       return lca;
    }
};

int main(){

    Tree t(13, 12);
    t.adjacencyList();
    cout<< t.lca(6, 12);

return 0;    
}