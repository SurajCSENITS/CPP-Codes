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

int main(){

    vector<int> arr= {-5,4,6,-3,4,-1};
    cout<< kadensAlgorithm(arr);

return 0;    
}
