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

const int INF= 1e+9;

vector<vector<int>> allPairShortest(int vert, int edge){
    vector<vector<int>> distance(vert+1, vector<int>(vert+1, INF));
    cout<< "Enter connected nodes: "<< endl;
    for(int i=0;i<edge;i++){
        int v1, v2, wt;
        cin>> v1>> v2>> wt;
        distance[v1][v2]= wt;
    }
    for(int v=1;v<=vert;v++) distance[v][v]= 0;

    for(int k=1;k<=vert;k++)
        for(int i=1;i<=vert;i++)
            for(int j=1;j<=vert;j++)
                distance[i][j]= min(distance[i][j], distance[i][k]+distance[k][j]);

    return distance;
}

int main(){

    vector<vector<int>> distance= allPairShortest(6, 9);
    for(int i=0;i<distance.size();i++){
        for(int j=0;j<distance[i].size();j++){
            if(distance[i][j]==INF) cout<< "I ";
            else cout<< distance[i][j]<< " ";
        }
        cout<< endl;
    }

return 0;    
}