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

int getPeakIndxInMountainArr(vector<int> arr){
    // peak-> maxm element in the array
    //     -> can never be present at the first and the last index
    int lo= 0;
    int hi= arr.size()-1;
    while(lo<=hi){
        int mid= (lo+hi)/2;
        if(mid!=0 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        if(mid==0 || arr[mid]>arr[mid-1]) lo= mid+1; // increasing curve
        else if(arr[mid]>arr[mid+1]) hi= mid-1; // decreasing curve
    }
    return -1; // not possible if arr is a mountain array
}

int main(){

    vector<int> arr= {0, 2, 5, 7, 8, 6, 4, 1};
    cout<< getPeakIndxInMountainArr(arr);

return 0;    
}
