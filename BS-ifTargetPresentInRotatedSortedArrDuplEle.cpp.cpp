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

bool ifTargetPresentInRotatedSortedArr(vector<int> arr, int target){
    // do elimination if first and last index elements are equal
    int i= 0; 
    if(arr[0]==arr[arr.size()-1]){
        if(target==arr[0]) return true;
        int n= arr.size()-1;
        while(arr[i]==arr[n-i]) i++;
    }
    // binary search for rest of rotated sorted array is independent of the presence of duplicate elements
    int lo= i; int hi= arr.size()-1-i;
    while(lo<=hi){ // logic from noted diagram in the copy
        int mid= (lo+hi)/2;
        if(arr[mid]==target) return true;
        if(arr[mid]>=arr[lo]){
            if(target>=arr[lo] && target<=arr[mid]) hi= mid-1;
            else lo= mid+1;
        }
        else{
            if(target>=arr[mid] && target<=arr[hi]) lo= mid+1;
            else hi= mid-1;
        }
    }
    return false;
}


int main(){

    vector<int> arr= {0,0,0,1,1,1,2,0,0,0};
    int target;
    cin>> target;
    cout<< ifTargetPresentInRotatedSortedArr(arr, target);

return 0;    
}
