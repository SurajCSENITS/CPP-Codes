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


int findMinInSortedRotatedArr(vector<int> arr){
    if(arr.size()==1) return 0;
    int lo= 0;
    int hi= arr.size()-1;
    while(lo<=hi){
        int mid= (lo+hi)/2;
        if(arr[mid]<arr[mid-1]) return mid;
        if(arr[mid]>arr[mid+1]) return mid+1;
        if(arr[mid]>arr[lo]) lo= mid+1;
        else hi= mid-1;
    }
    return -1;
}

int binarySearch(vector<int>& input, int target, int lo, int hi){// input can be sorted on the basis of some property
    while(lo<=hi){
        int mid= (lo+hi)/2; // calculate mid point
        if(input[mid]==target) return mid;
        if(input[mid]<target) lo= mid+1; // discard left part
        else hi= mid-1; // discard right part
    }

    return -1;
}

int targetInSortedRotatedArr(vector<int> arr, int target){
    int minEleIdx= findMinInSortedRotatedArr(arr); // 0 to minIdx-1 and minIdx to last idx are two separate sorted arrays
    // apply BS on two sorted arrays
    int idx= binarySearch(arr, target, 0, minEleIdx-1);
    if(idx==-1) idx= binarySearch(arr, target, minEleIdx, arr.size()-1);
    
    return idx;
}

int main(){

    vector<int> arr= {3,4,5,1,2};
    int target;
    cin>> target;
    cout<< targetInSortedRotatedArr(arr, target);

return 0;    
}
