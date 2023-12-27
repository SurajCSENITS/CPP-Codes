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

vector<int> getPair(int array[], int n, int target)
{// elements should be unique
    // insert elements in map
    multimap<int, int> m;
    vector<int> result;
    // method 2
    for(int i=0;i<n;i++){
        if(m.find(target-array[i])==m.end()){
            m.insert(make_pair(array[i], i));
            continue;
        }
        result.push_back(i);
        result.push_back(m.find(target-array[i])->second);
        return result;
    }
    // method 1 -> first all the elements of array in multimap
    // check
    // vector<int> result;
    // for(auto pair: m){
    //     if(m.find(target-pair.first)==m.end() || m.find(target-pair.first)->second==pair.second) continue;
    //     result.push_back(pair.second);
    //     result.push_back(m.find(target-pair.first)->second);
    //     return result;
    // }
    result.push_back(-1);
    return result;
}

int main(){

    int array[]= {1,4,5,11,13,10,2};
    int n= sizeof(array)/sizeof(array[0]);
    int target;
    cin>> target;
    vector<int> result= getPair(array, n, target);
    for(int ele: result)
        cout<<ele<<" ";

return 0;    
}
