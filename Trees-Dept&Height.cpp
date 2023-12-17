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
class Tree
{
public:
    int vert;
    int edge;
    vector<vector<int>> v;

    Tree(int n, int m){
        vert= n;
        edge= m;
        v.resize(vert+1);
        for(int i= 0;i<=vert; ++i) 
            v[i].push_back(-1);    
    }
    void createTree(){ // no. of inputs = no. of egdes
        cout<< "Enter inputs for the Tree:"<<endl;
        for(int i=0;i<edge;i++){
            int v1, v2;
            cin>>v1>>v2;
            if(v[v1][0]==-1) v[v1].pop_back(); // leaf nodes are carrying -1    
            v[v1].push_back(v2);
        }
    }    
};
void dfsTree(Tree t, int i, vector<int>& dept, vector<int>& height){
    if(t.v[i][0]==-1) return; // leaf node
    for(int child: t.v[i]){
        dept[child]= dept[i] + 1;
        dfsTree(t, child, dept, height);
        height[i]= max(height[i], height[child]+1); // vapas laut te vakt
    }
}


int main(){

    // leaf node -> height
    // root node -> dept
    Tree t(13, 12);
    t.createTree();
    vector<int> dept(t.vert+1, 0);
    vector<int> height(t.vert+1, 0);
    dfsTree(t, 1, dept, height);
    for(int i=1;i<=t.vert;i++){
        cout<< dept[i]<<" "<<height[i];
        cout<< endl;
    }

return 0;    
}