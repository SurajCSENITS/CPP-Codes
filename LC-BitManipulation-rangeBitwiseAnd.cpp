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

int rangeBitwiseAnd(int left, int right){
    // all the cols to the right of the flipped bit is also flipped
    // leftmost consequtive common bits k right wale sabhi bits ka & 0 hoga ***
    // How to find the leftmost common(betn left and right) consequtive bits ?
    // by checking(left and right) and right-shifting
    int count= 0;
    while(left!=right){
        left= left>>1;
        right= right>>1;
        count++;
    }
    return left<<count;
}

int main(){

    int left= 5, right= 7;
    cout<< rangeBitwiseAnd(left, right);

return 0;    
}
