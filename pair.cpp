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

bool myComparision(pair<int, int> p1, pair<int, int> p2){ // jis datatype ka vector he usi datatype ka do value lega
    return p1.first<p2.first;
}

void reduceArray(int array[], int n)
{
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++)
        v.push_back(make_pair(array[i], i)); // inserting value and index pair inside the vector
    // sort the array by taking care of its previous indices
    sort(v.begin(), v.end(), myComparision);
    for(int i=0;i<n;i++)
        array[v[i].second]= i;        
}

int main(){

    // pair<int, char> p;
    // p.first= 3;
    // p.second= 'f';

    int array[]= {10,16,7,14,5,3,12,9};
    int n= sizeof(array)/sizeof(array[0]);
    reduceArray(array, n);
    for(int i=0;i<n;i++)
        cout<< array[i]<<" ";

return 0;    
}
