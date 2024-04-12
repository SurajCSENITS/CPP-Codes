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


bool customComparator(pair<int, int> a, pair<int, int> b){
    // data type of a and b is same as data type of 'v' elements
    // b a ke baad aa rha he
    if(a.first==b.first) return a.second>b.second; // a and b ka first same and a b k pehle aa rha h matlab a.second must be greater than b.second
    return a.first<b.first;
}

int main(){

    vector<pair<int, int>> v= {{5,0},{4,1},{3,2},{3,10},{1,5}};
    sort(v.begin(), v.end(), customComparator);

return 0;
}