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


int maximumPopulation(vector<vector<int>>& logs){ // YT Channel -> Code Explainer
    // first find the maxm range i.e., the min birth year and the max death year
    int minBirthYr= 1950, maxDeathYr= 2050; // Given

    // create a range vector containing all the years & initialise with 0
    vector<int> v(maxDeathYr-minBirthYr+1, 0); // 0th idx->minBirthYr last_idx->maxDeathYr
    for(auto row: logs){ // O(row)
        int l= row[0], r= row[1];
        while(l<r){ // death year is not being taken
            v[l-minBirthYr]+=1;
            l++;
        }
    }
    
    // find the first max value in 'v'
    int maxm= INT32_MIN;
    int ansYr;
    for(int i=0;i<v.size();i++){ // O(maxDeathYr-minBirthYr)
        if(maxm<v[i]){
            maxm= v[i];
            ansYr= i+minBirthYr;
        }
    }
    return ansYr;
}

int main(){

    vector<vector<int>> logs= {{1993,1999},{2000,2010}};
    cout<< maximumPopulation(logs);


return 0;    
}
