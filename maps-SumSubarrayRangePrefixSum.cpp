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

int getSubarrayLength(int array[], int n)
{// prefix sum approach 1:20 hr lect 62
    unordered_map<int, int> m;
    vector<int> prefixSum(n);
    int range= 0;
    for(int i=0;i<n;i++){
        if(i==0){
            prefixSum[i]= array[i];
            m.insert(make_pair(prefixSum[i], i));
            continue;
        }
        prefixSum[i]= array[i]+prefixSum[i-1];
        if(m.find(prefixSum[i])!=m.end()) range= max(range, i-m.find(prefixSum[i])->second);
        m.insert(make_pair(prefixSum[i], i));      
    }
    return range;
}

int main(){

    int array[]= {15,-2,2,-8,1,7,10,23};
    int n= sizeof(array)/sizeof(array[0]);
    cout<< getSubarrayLength(array, n); //target sum = 0

return 0;    
}
