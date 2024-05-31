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

// paint using one element to the other element
// duplicate elements will try to pain the same element
vector<int> findDuplicates(vector<int>& nums){ // https://youtu.be/aMsSF1Il3IY
    // ele-1 == idx approach | when 1<=ele<=n | SC: O(1)
    int n= nums.size();
    vector<int> answer;
    for(int ele: nums){
        int idx= abs(ele)-1;
        if(nums[idx]<0) answer.push_back(abs(ele));
        else nums[idx]= -nums[idx];
    }
    return answer;
}

int main(){    



return 0;
}