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

void prefixsumSubmatrix(vector<vector<int>>& matrix){
    // sum = curr~ + top + left - top_left, ~from original given matrix
    int m= matrix.size(), n= matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int sum= matrix[i][j] + (i>0?matrix[i-1][j]:0) + (j>0?matrix[i][j-1]:0) - (i>0&&j>0?matrix[i-1][j-1]:0);
            matrix[i][j]= sum;
        }
    }
}

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target){
    //  calculate the prefix submatrix
    prefixsumSubmatrix(matrix);
    // iterate using three pointers
    // storing the curr_sum - target sum = diff in map
    map<int, int> mp; // {diff - count}

    int m= matrix.size(), n= matrix[0].size();
    int count= 0;
    for(int ri=0;ri<m;ri++){
        for(int rf=ri;rf<m;rf++){
            mp.clear();
            mp.insert({0, 1});
            for(int c=0;c<n;c++){
                // curr_sum = (rf,c) - (ri-1,c)
                int curr_sum= matrix[rf][c] - (ri>0 ? matrix[ri-1][c] : 0);
                
                int diff= curr_sum-target;
                if(mp.count(diff)!=0) count+= mp[diff]; // prefixsumSubmatrix of sum diff exists

                if(mp.count(curr_sum)==0) mp[curr_sum]= 1;
                else mp[curr_sum]+= 1;
            }
        }
    }
    return count;
}

int main(){

    vector<vector<int>> matrix= {{0,1,0},{1,1,1},{0,1,0}};
    int target= 0;
    cout<< numSubmatrixSumTarget(matrix, target);

return 0;
}