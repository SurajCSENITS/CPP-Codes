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


void prefixSum(vector<int>& v){
    for(int i=2;i<v.size();i++) v[i]= v[i]+v[i-1]; // 1th base indexing
}

void sumInRange(vector<int>& v){ // 1th base indexing
    int q= 3;
    int l, r;
    prefixSum(v);
    while(q>0){
        cin>> l>> r;
        cout<< v[r]-v[l-1]<< endl;
        q--;
    }
}


int main(){

    vector<int> v= {0,5,1,2,3,4};
    sumInRange(v);

return 0;    
}
