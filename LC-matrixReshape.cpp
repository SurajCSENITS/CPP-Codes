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

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c){
    int m= mat.size(); // no of rows
    int n= mat[0].size(); // no of columns
    // whether reshaping is possible or not for the given r and c
    if(r*c!=m*n) return mat;

    // define reshaped matrix
    vector<vector<int>> reshaped(r);
    for(int i=0;i<r;i++) mat[i].resize(c);
    // insert elements in row-traversing order
    int p= 0, q= 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            reshaped[i][j]= mat[p][q++];
            if(q==n){
                p++;
                q= 0;
            }
        }
    }
    return reshaped;
}

int main(){

    vector<vector<int>> mat= {{1,2},{3,4}};
    int r= 1, c= 4;
    vector<vector<int>> reshaped= matrixReshape(mat, r, c);
    
return 0;    
}
