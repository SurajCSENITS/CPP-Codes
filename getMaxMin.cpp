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


pair<int, int> getMaxMin(vector<int>& arr){
    // create variables maxm and minm
    int maxm= INT32_MIN, minm= INT32_MAX;
    // create two pointers l and r
    int l= 0, r= arr.size()-1;
    while(l<=r){
        maxm= max(maxm, max(arr[l], arr[r]));
        minm= min(minm, min(arr[l], arr[r]));
        l++; r--;
    }

    return make_pair(maxm, minm);
}

int main(){

    vector<int> arr= {5,1,3,8,4,6,2,7};
    pair<int, int> result= getMaxMin(arr);
    cout<< result.first<<" "<< result.second;

return 0;    
}
