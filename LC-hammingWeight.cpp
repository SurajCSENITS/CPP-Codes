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

int hammingWeight(uint32_t n){ // number of 1s in the binary representation of an uint
    vector<int> v(2, 0);
    for(int i= 31;i>=0;i--){
        int mask= 1<<i;
        if((n&mask)!=0) v[1]++;// counts no. of 1 bits
        else v[0]++;// counts no. of 0 bits
    }
    return v[1];
}

int main(){

    uint32_t n;
    cin>> n;
    cout<< hammingWeight(n);

return 0;    
}
