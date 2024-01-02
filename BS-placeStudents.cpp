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

int placeStudents(vector<int> spots, vector<int> std){
    int n= spots.size();
    int lo= 1; //minm possible distance betn two students
    int hi= spots[n-1]-spots[0]; // maxm possible distance betn two students
    int ans= -1;
    bool flag= true;

    while(lo<=hi){
        int mid= (lo+hi)/2;
        std[0]= spots[0]; // place first student at first spot

        int j= 1;
        for(int i=1;i<std.size();i++){
            for(;j<n;j++){
                if(spots[j]-std[i-1]>=mid){
                    std[i]= spots[j];  
                    j++;
                    break;
                }   
            }
                        
            if(std[i]==-1){ 
                // reinitialise the std vector with -1
                for(int k=0;k<std.size();k++) std[k]= -1;
                hi= mid-1;  
                flag= false;   
                break;   
            }
        }
        if(flag){
            ans= mid;
            lo= mid+1;
        }
        flag= true;
    }
    return ans;
}

// 2nd method
bool canPlaceStd(vector<int> spots, int s, int mid){// can we place students maintaining atleast mid distance
    int stdPlaced= 1;
    int lastPlaced= spots[0];
    for(int i=1;i<spots.size();i++){
        if(spots[i]-lastPlaced>=mid){
            stdPlaced++;
            lastPlaced= spots[i];
            if(stdPlaced==s) return true;
        }
    }
    return false;
}

int race(vector<int> spots, int s){
    int n= spots.size();
    int lo= 1;
    int hi= spots[n-1]-spots[0];
    int ans= -1;
    while(lo<=hi){
        int mid= lo+(hi-lo)/2;
        if(canPlaceStd(spots, s, mid)){
            ans= mid;
            lo= mid+1;
        }
        else hi= mid-1;
    }
    return ans;
}

int main(){

    vector<int> spots= {1,2,4,8,9};
    int s;
    cin>> s; // s>=2
    vector<int> std(s, -1);
    cout<< placeStudents(spots, std);
    
return 0;    
}
