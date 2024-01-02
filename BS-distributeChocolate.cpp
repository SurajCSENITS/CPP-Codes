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


bool canDistribute(vector<int> arr, int mid, int s){
    int n= arr.size();
    int stdReq= 1;
    int currentSum= 0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid) return false;
        if(currentSum+arr[i]>mid){
            stdReq++;
            currentSum= arr[i];
            if(stdReq>s) return false;
        }
        else currentSum+= arr[i];
    }
    return true;
}

int distribute(vector<int> arr, int s){
    int n= arr.size();
    int lo= arr[0];
    int hi= 0;
    for(int i=0;i<arr.size();i++) hi+=arr[i];
    int ans= -1;
    while(lo<=hi){
        int mid= (lo+hi)/2;
        if(canDistribute(arr, mid, s)){// can we distribute atmost mid no. of chocolates to s no. of students
            ans= mid;
            hi= mid-1;
        }
        else lo= mid+1;
    }
    return ans;
}

int main(){

    vector<int> chocolate= {12,34,67,90};
    int s;
    cin>>s;
    cout<< distribute(chocolate, s);

return 0;    
}
