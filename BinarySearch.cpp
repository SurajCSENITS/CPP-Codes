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

int binarySearch(vector<int>& input, int target){// input is sorted on the basis of some property
    // define search space
    int lo= 0;
    int hi= input.size()-1;
    
    while(lo<=hi){
        int mid= (lo+hi)/2; // calculate mid point
        if(input[mid]==target) return mid;
        if(input[mid]<target) lo= mid+1; // discard left part
        else hi= mid-1; // discard right part
    }

    return -1;
}

int binarySearch_reccursion(vector<int>& input, int target, int lo, int hi){
    if(lo>hi) return -1;
    int mid= (lo+hi)/2;
    if(input[mid]==target) return mid;
    if(input[mid]<target) return binarySearch_reccursion(input, target, mid+1, hi);
    else return binarySearch_reccursion(input, target, lo, mid-1);
}

int main(){

    // Binary Search is not affected by duplicate elements in a sorted array/rotated sorted array*
    // * -> first and last index elements should be differrent

return 0;    
}
