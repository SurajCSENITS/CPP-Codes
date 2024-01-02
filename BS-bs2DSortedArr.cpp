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

int binarySearch(vector<int> input, int target){
    int lo= 0;
    int hi= input.size()-1;
    
    while(lo<=hi){
        int mid= (lo+hi)/2;
        if(input[mid]==target) return mid;
        if(input[mid]<target) lo= mid+1;
        else hi= mid-1;
    }

    return -1;
}

bool bs2DSortedArr(vector<vector<int>> matrix, int target){
    int lo= 0;
    int hi= matrix.size()-1;
    while(lo<=hi){
        int mid= (lo+hi)/2;
        if(matrix[mid][0]>target) hi= mid-1;
        else if(matrix[mid][0]<=target){// go inside matrix[mid] and perform BS if res==-1 then lo=mid+1
            int ans= binarySearch(matrix[mid], target);
            if(ans!=-1) return true;
            lo= mid+1;
        }
    }
    return false;
}


int main(){

    vector<vector<int>> matrix= {{1,3,5,7,},{10,11,16,20},{23,30,34,60}};
    int target;
    cin>> target;
    cout<< bs2DSortedArr(matrix, target);

return 0;    
}
