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

void dfsTree(int dept[], Tree t, int i, int count= 0){
    dept[i]= count;
    if(t.v[i][0] == -1) return;
    count++;
    for(int child: t.v[i]){
        dfsTree(dept, t, child, count);
    }
}

int* findDept(Tree t){
    int* dept= new int[t.vert+1];
    dfsTree(dept, t, 1);
    return dept;
}

int main(){

    Tree t(13, 12);
    t.createTree();
    int* dept= findDept(t);
    for(int i=1;i<=t.vert;i++)
        cout<< dept[i]<<" ";

return 0;    
}