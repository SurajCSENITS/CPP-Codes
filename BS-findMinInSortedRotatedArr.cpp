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
    if(arr[lo]<arr[hi]) return lo;
    while(lo<=hi){
        int mid= (lo+hi)/2;
        if(arr[mid]<arr[mid-1]) return mid;
        if(arr[mid]>arr[mid+1]) return mid+1;
        if(arr[mid]>arr[lo]) lo= mid+1;
        else hi= mid-1;
    }
    return -1;
}

int main(){

    vector<int> arr= {5,1,2,3,4};
    cout<< findMinInSortedRotatedArr(arr);

return 0;    
}
