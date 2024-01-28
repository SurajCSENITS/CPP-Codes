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



// int maxSubsequence(vector<int>& nums, int sum){ // select minm elements to increase the count
//     // subsequence ko random selection hi consider karo
//     int len= 0;
//     for(int ele: nums){
//         if(ele>=sum) return len;
//         sum= sum-ele;
//         len++;
//     }
//     return len;
// }

vector<int> answerQueries(vector<int>& nums, vector<int>& queries){ // subsequence ko random selection hi consider karo
    // sort nums
    sort(nums.begin(), nums.end());
    // prefix sum of nums -> each length k subsequence ka minm sum kitna ho sakta hai
    nums.insert(nums.begin(), 0);
    for(int i=1;i<nums.size();i++) nums[i]+=nums[i-1];

    vector<int> answer;
    for(int sum: queries){
        int l= 0, r= nums.size()-1;
        int ans= -1;
        while(l<=r){ // searching the max possible length
            int mid= (l+r)/2;
            if(nums[mid]<=sum){
                ans= mid; 
                l= mid+1;
            }
            else r= mid-1;
        }
        answer.push_back(ans);
    }

    return answer;
}

int main(){

    vector<int> nums= {4,5,2,1};
    vector<int> queries= {3,10,21};
    vector<int> answer= answerQueries(nums, queries);
    for(int ele: answer) cout<< ele<< " ";


return 0;    
}
