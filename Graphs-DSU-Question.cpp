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

int findRoot(vector<int>& parent, int v){
    if(parent[v]==v) return v;
    return parent[v]= findRoot(parent, parent[v]);
}

void outputDiff(int n, int q){
    vector<int> parent(n+1);
    vector<int> size(n+1);
    multiset<int> st; // at any instant sizes of all groups

    for(int i=1;i<=n;i++) parent[i]= i, size[i]= 1, st.insert(1);
    while(q){
        int a, b;
        cin>> a>> b;
        a= findRoot(parent, a);
        b= findRoot(parent, b);
        if(a!=b){
            st.erase(st.find(size[a])), st.erase(st.find(size[b]));
            st.insert(size[a]+size[b]);
            if(size[a]<size[b]) swap(a, b);
            parent[b]= a, size[a]+= size[b];
        }
        int mx= *(--st.end());
        int mn= *(st.begin());
        cout<< mx-mn<< " ";
        q--;
    }
}

int main(){



return 0;    
}