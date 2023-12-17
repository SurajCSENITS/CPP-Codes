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

void subtreeSum(Tree t, vector<int>& ss, vector<int>& ec, int i= 1){
    ss[i]+=i;
    if(i%2==0) ec[i]++;
    if(t.v[i][0]==-1) return; // leaf nodes are carrying -1 
    for(int child: t.v[i]){
        subtreeSum(t, ss, ec, child);
        ss[i]+= ss[child];
        ec[i]+= ec[child];
    }
}


int main(){

    Tree t(13, 12);
    t.createTree();
    vector<int> subtree_sum(t.vert+1, 0);
    vector<int> even_count(t.vert+1, 0);
    subtreeSum(t, subtree_sum, even_count);
    for(int i=1;i<=t.vert;i++){
        cout<< subtree_sum[i]<<" "<< even_count[i];
        cout<< endl;
    }

return 0;    
}