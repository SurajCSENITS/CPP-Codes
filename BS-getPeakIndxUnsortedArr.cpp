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

int getPeakIndx(vector<int> arr, int lo, int hi){ // peak element is the one which is strictly greater than its neighbours
                                                  // take arr[-1]=arr[n]= -INF 
                                                  // if more than one peak then return anyone of them
    while(lo<=hi){ 
        int mid= (lo+hi)/2;
        if(mid==0 && arr[mid]>arr[mid+1]) return mid;
        if(mid==arr.size()-1 && arr[mid]>arr[mid-1]) return mid;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        int ans= getPeakIndx(arr, mid+1, hi);// have to check both portions
        if(ans==-1) return getPeakIndx(arr, lo, mid-1);// have to check both portions
        return ans;
    }
    return -1;
}

// without reccursion-> logic from diagram of unsorted mountain array
//                   -> if mid lies on increasing curve discard the left part
//                   -> if mid lies on decreasing curve discard the right part

int main(){

    vector<int> arr= {1,2,1,2,6,10,3}; // unsorted array
    cout<< getPeakIndx(arr, 0, arr.size()-1);

return 0;    
}
