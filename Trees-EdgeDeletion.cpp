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

void subtreeSum(vector<vector<int>> v, int vertex, vector<int>& ss, vector<int> weight, int par= 0){
    ss[vertex]+= weight[vertex];
    for(int child: v[vertex]){
        if(child==par) continue;
        subtreeSum(v, child, ss, weight, vertex);
        ss[vertex]+= ss[child];
    }
}

int main(){

    int vert= 4;
    int edge= 3;
    vector<vector<int>> v; 
    v.resize(vert+1);
    cout<<"Enter adjacent vertices(a pair should be entered only once, irrespective of its order)"<<endl;
    for(int i=0;i<edge;i++){
        int v1, v2;
        cin>>v1>>v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    // precomputation
    vector<int> ss(vert+1, 0);
    vector<int> weight= {-1, 10, 5, 12, 6};
    subtreeSum(v, 1, ss, weight);
    
    int mProduct= 0;
    int v1, v2;
    vector<bool> isCheck(vert+1, false);
    for(int i=1;i<=vert;i++){
        for(int child: v[i]){
            if(isCheck[i] && isCheck[child]) continue;
            if(mProduct < ss[i]*ss[child]){
                mProduct= ss[i]*ss[child];
                v1= i; v2= child;
            }
            isCheck[child]= true;
        }
        isCheck[i]= true;
    }
    printf("%d (%d,%d)", mProduct, v1, v2);

return 0;    
}
