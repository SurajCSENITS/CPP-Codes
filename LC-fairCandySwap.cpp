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


int sum(vector<int>& arr){
    int ans= 0;
    for(int ele: arr) ans+= ele;
    return ans;
}

vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes){
    int aliceSum= sum(aliceSizes);
    int totalSum= aliceSum+sum(bobSizes); // conservation of total sum
    int equalSum= totalSum/2; // ***
    vector<int> res;
    for(int i=0;i<aliceSizes.size();i++){
        int reqEle= equalSum-(aliceSum-aliceSizes[i]);
        if(reqEle>0 && (find(bobSizes.begin(), bobSizes.end(), reqEle)!=bobSizes.end())){
            res.push_back(aliceSizes[i]);
            res.push_back(reqEle);
            return res;
        }
    }
    return res;
}

int main(){

    vector<int> aliceSizes= {2};
    vector<int> bobSizes= {1,3};
    vector<int> res= fairCandySwap(aliceSizes, bobSizes);
    cout<< res[0]<<" "<<res[1];

return 0;    
}
