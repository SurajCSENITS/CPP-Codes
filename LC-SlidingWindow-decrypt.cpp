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

vector<int> decrypt(vector<int>& code, int k){
    int n= code.size();
    vector<int> decrV;
    deque<int> dq;

    if(k==0){
        decrV.resize(n, 0);
        return decrV;
    }

    if(k>0){
        // first time calculate the sum of next k elements for idx 0
        int count= k, i= 1, nextSum= 0;
        while(count>0){
            nextSum+= code[i];
            dq.push_back(code[i]);
            i= (i+1)%n;
            count-=1;
        }

        count= n;
        while(count>0){
            decrV.push_back(nextSum);
            nextSum-= dq.front();
            dq.pop_front(); // window right shift
            dq.push_back(code[i]);
            nextSum+= code[i];
            i= (i+1)%n;
            count--;
        }
        return decrV;
    }

    int count= abs(k), i= n-1, prevSum= 0;
    while(count>0){
        prevSum+= code[i];
        dq.push_back(code[i]);
        i= (i-1+n)%n;
        count-=1;
    }

    count= n;
    while(count>0){
        decrV.push_back(prevSum);
        prevSum-= dq.back();
        dq.pop_back(); // window left shift
        dq.push_front(code[n-count]);
        prevSum+= code[n-count];
        count--;
    }
    return decrV;

}

int main(){

    vector<int> code= {5,7,1,4};
    int k= 3;
    vector<int> decrV= decrypt(code, k);
    for(int ele: decrV) cout<< ele<< " ";


return 0;    
}
