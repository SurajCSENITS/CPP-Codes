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


int longestSumSubArray(vector<int>& v, int k){
    int ans= 0;
    deque<int> dq;
    
    int i= 0;
    int sum= 0;
    while(i<v.size()){
        if(sum+v[i]>k){
            while(dq.size()>ans){
                sum-= dq.back();
                dq.pop_back();
                i--;
            }
            sum-= dq.front();
            dq.pop_front();
            sum+= v[i];
            dq.push_back(v[i]);
            i++;
        }
        else{ // *** added
            dq.push_back(v[i]);
            sum+= v[i];
            if(sum==k) ans= dq.size();
            i++;
        }
    }
    return ans;
}

int main(){

    vector<int> v= {4,1,1,1,2,3,5};
    cout<< longestSumSubArray(v, 5);

return 0;    
}
