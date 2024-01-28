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


vector<int> prefixSum(vector<int> v){
    for(int i=1;i<v.size();i++) v[i]= v[i]+v[i-1]; 
    return v;      
}

vector<int> suffixSum(vector<int> v){
    for(int j= v.size()-2;j>=0;j--) v[j]= v[j]+v[j+1];
    return v;
}

bool canDivide(vector<int>& v){
    vector<int> prefixV= prefixSum(v);
    vector<int> suffixV= suffixSum(v);
    for(int i=0;i<v.size()-1;i++) {if(prefixV[i]==suffixV[i+1]) return true;}
    return false;
}

int main(){

    // prefix sum till i + suffix sum of i+1 = total sum
    vector<int> v= {1,2,3,4,6,2,2};
    cout<< canDivide(v);

return 0;    
}
