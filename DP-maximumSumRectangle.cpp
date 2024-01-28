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

int kadensAlgorithm(vector<int>& arr){// maxm sum subarray O(n)
    int maxSum= INT32_MIN;
    int currSum= 0;
    for(int i=0;i<arr.size();i++){
        currSum+= arr[i];
        maxSum= max(currSum, maxSum);
        // if the contribution of the current subarray is -ve then discard it
        if(currSum<0) currSum= 0;
    }
    return maxSum;
}

int maximumSumRectangle(vector<vector<int>>& matrix){
    int maxSum= INT32_MIN;
    int r= matrix.size(); // row number
    int c= matrix[0].size(); // column number
    for(int c_start=0;c_start<c;c_start++){// O(c^2)*(O(r)+O(r))
        vector<int> temp(r, 0);
        for(int c_end=c_start;c_end<c;c_end++){ 
            int currSum= 0;
            for(int i=0;i<r;i++) temp[i]+= matrix[i][c_end];
            currSum= kadensAlgorithm(temp);
            
            maxSum= max(maxSum, currSum);
        }
    }

    return maxSum;
}

int main(){

    vector<vector<int>> matrix= {{1,2,-1,-4,-20},{-8,-3,4,-2,1},{3,8,9,1,3},{-4,-1,1,7,-6},{-2,-3,8,1,-1}};
    cout<< maximumSumRectangle(matrix);

return 0;    
}
