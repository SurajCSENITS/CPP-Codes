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
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>  

vector<int> assemblyLineScheduling(vector<vector<int>>& line, vector<vector<int>>& transfer, vector<int>& e, vector<int>& x){
    int n= line[1].size()-1;
    vector<vector<int>> f(2+1); // storing the total min cost till each station of each line
    for(auto &row: f) row.resize(n+1);
    vector<vector<int>> l(2+1); // reached the station through which line
    for(auto &row: l) row.resize(n+1);

    // pre-fill
    f[1][1]= e[1]+line[1][1]; l[1][1]= 1;
    f[2][1]= e[2]+line[2][1]; l[2][1]= 2;

    for(int j=2;j<=n;j++){ // jth station
        f[1][j]= min(line[1][j]+f[1][j-1], line[1][j]+transfer[2][j]+f[2][j-1]);
        if(line[1][j]+f[1][j-1] < line[1][j]+transfer[2][j]+f[2][j-1]) l[1][j]= 1;
        else l[1][j]= 2;

        f[2][j]= min(line[2][j]+f[2][j-1], line[2][j]+transfer[1][j]+f[1][j-1]);
        if(line[2][j]+f[2][j-1] < line[2][j]+transfer[1][j]+f[1][j-1]) l[2][j]= 2;
        else l[2][j]= 1;
    }

    // exit time
    int f_star= min(f[1][n]+x[1], f[2][n]+x[2]); // final minm cost
    int l_star; // line of exit
    if(f[1][n]+x[1] < f[2][n]+x[2]) l_star= 1;
    else l_star= 2;

    // backtracking to get the path
    vector<int> path;
    int k= n;
    int i= l_star;
    while(k>0){
        path.insert(path.begin(), i);
        i= l[i][k];
        k--;
    }

    return path;
    
}

int main(){

    vector<vector<int>> line= {{},{-1,7,9,3,4,8,4},{-1,8,5,6,4,5,7}};
    vector<vector<int>> transfer= {{},{-1,-1,2,3,1,3,4},{-1,-1,2,1,2,2,1}};
    vector<int> e= {-1,2,4};
    vector<int> x= {-1,3,2};
    vector<int> path= assemblyLineScheduling(line, transfer, e, x);
    for(int ele: path) cout<< ele<<" ";

return 0;    
}
