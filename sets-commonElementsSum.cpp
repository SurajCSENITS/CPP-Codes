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
#include <bits/stdc++.h>  

int main(){

    vector<int> v1= {1,1,2,3,3,3};
    vector<int> v2= {5,6,7,5,2,3,6};
    // make s1 & s2 from v1 & v2
    set<int> s1; set<int> s2;
    int minSize= min(v1.size(), v2.size());
    int i= 0;
    for(;i<minSize;i++){
        s1.insert(v1[i]);
        s2.insert(v2[i]);
    }
    if(minSize==v1.size()){
        for(;i<v2.size();i++)
            s2.insert(v2[i]);
    }
    else{
        for(;i<v1.size();i++)
            s1.insert(v1[i]);
    }
    // now find common elements betn s1 and s2 and their sum
    set<int> commons;
    if(s1.size()<s2.size()){
        set<int>::iterator itr= s1.begin();
        while(itr!=s1.end()){
            if(s2.find(*itr)!=s2.end())
                commons.insert(*itr);
            itr++;
        }
    }
    else{
        set<int>::iterator itr= s2.begin();
        while(itr!=s2.end()){
            if(s1.find(*itr)!=s1.end())
                commons.insert(*itr);
            itr++;
        } 
    }

    int sum= 0;
    for(int ele: commons){
        cout<<ele<<" ";
        sum+= ele;
    }
    cout<<sum;
    


return 0;    
}
