#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>

bool isPowerOfTwo(int n){
    // Corner Cases
    if(n<=0) return false;
    
    int mask= 1; // 0000...001
    int bits_req= ceil(log2(n)); // num of bits in n
    bool flag= false;
    for(int i=0;i<bits_req;i++){ // we have to check bit_req no. of bits
        // check if the lsb is 0
        if((n&mask)==0){
            n= n>>1; // right shift
            continue;
        }
        // if lsb is 1
        if(flag) return false;
        n= n>>1; // right shift
        flag= true;
    }
    return true;
}

int main(){

    int n= 0;
    cout<< isPowerOfTwo(n);

return 0;    
}
