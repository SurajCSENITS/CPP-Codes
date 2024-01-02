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

bool checkValid(vector<vector<int>>& matrix){
    int n= matrix.size();
    set<int> s;
    for(int i=0;i<n;i++){
        // check for rows(ith row)
        for(int j=0;j<n;j++) s.insert(matrix[i][j]);
        if(s.size()!=n) return false;
        // check for columns(ith column)
        s.clear();
        for(int j=0;j<n;j++) s.insert(matrix[j][i]);
        if(s.size()!=n) return false;
        s.clear();
    }
    return true;
}

int main(){

   
return 0;    
}
