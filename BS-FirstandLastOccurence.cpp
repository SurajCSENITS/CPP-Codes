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

int getFirstOccurence(vector<int>& arr, int target, int lo, int hi, int canditate= -1){// lowerbound
    if(lo>hi) return canditate;
    int mid= (lo+hi)/2;
    if(arr[mid]==target){
        canditate= mid;
        return getFirstOccurence(arr, target, lo, mid-1, canditate);
    }
    if(arr[mid]>target) return getFirstOccurence(arr, target, lo, mid-1, canditate);
    else return getFirstOccurence(arr, target, mid+1, hi, canditate); 
}

int getLastOccurence(vector<int>& arr, int target, int lo, int hi, int canditate= -1){// upperbound
    if(lo>hi) return canditate;
    int mid= (lo+hi)/2;
    if(arr[mid]==target){
        canditate= mid;
        return getLastOccurence(arr, target, mid+1, hi, canditate);
    }
    if(arr[mid]<target) return getLastOccurence(arr, target, mid+1, hi, canditate);
    else return getLastOccurence(arr, target, lo, mid-1, canditate); 
}

// without reccursion
int lowerbound(vector<int>& arr, int target){// firstOccurence
    int lo= 0;
    int hi= arr.size()-1;
    int canditate= -1;
    while(lo<=hi){
        int mid= (lo+hi)/2;
        if(arr[mid]==target){
            canditate= mid;
            hi= mid-1;
        }
        else if(arr[mid]>target) hi= mid-1;
        else lo= mid+1;
    }
    return canditate;
}

int upperbound(vector<int>& arr, int target){// first greater value of target
    int lo= 0;
    int hi= arr.size()-1;
    int canditate= -1;
    while(lo<=hi){
        int mid= (lo+hi)/2;
        if(arr[mid]==target) lo= mid+1;
        else if(arr[mid]>target){
            canditate= mid;
            hi= mid-1;
        }
        else lo= mid+1;
    }
    return canditate;
}

int main(){

    vector<int> arr= {1,2,3,3,3,5,11};
    int target;
    cin>> target;
    int first= getFirstOccurence(arr, target, 0, arr.size()-1);
    int last= -1;
    if(first!=-1) last= getLastOccurence(arr, target, 0, arr.size()-1);
    vector<int> res= {first, last};
    cout<<res[0]<<" "<<res[1]<<endl;

return 0;    
}
