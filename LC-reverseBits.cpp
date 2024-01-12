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

uint32_t reverseBits(uint32_t n){
    uint32_t rev= 0; // all 32 bits are 0
    int j= 0;
    for(int i=31;i>=0;i--){
        int mask= 1<<i;
        if((n&mask)!=0) rev= rev|(1<<j);
        j++;
    }
    return rev;
}

int main(){

    uint32_t n;
    cin>> n;
    cout<< reverseBits(n);
 

return 0;    
}
