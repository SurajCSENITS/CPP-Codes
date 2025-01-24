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
#include <bitset>
#include <tuple>
#include <bits/stdc++.h>

vector<int> maxOfSubarrays(vector<int>& nums, int k){
    // create a sliding window 
    deque<int> dq;
    // process the first `k` elements
    int i= 0;
    for(i;i<k;i++){
        if(dq.empty()){
            dq.push_back(i);
            continue;
        }

        while(!dq.empty() and nums[i]>=nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }

    vector<int> answer;
    answer.push_back(nums[dq.front()]);
    // slide window for rest of elements
    while(i<nums.size()){
        while(!dq.empty() and nums[i]>=nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
        answer.push_back(nums[dq.front()]);
    }
    return answer;
}

int longestSubstringKUniqueChar(string str, int k){
    // two pointers for maintaining the window
    // map to keep track of the freq of char
    int l= 0, r= 0, mxLen= -1;
    map<char, int> freq;
    
    while(r<str.length()){
        freq[str[r]]+=1;
        if(freq.size()==k) mxLen= max(mxLen, r-l+1);
        while(freq.size()>k){
            freq[str[l]]-=1;
            if(freq[str[l]]==0) freq.erase(str[l]);
            l++;
        }
        r+=1;
    }
    return mxLen;
}

int longestSubstringNoRepeating(string str){
    // set : to strore the unique chars
    // deque : for the sliding window
    // ending pointer approach 
    /*

    int l= str.length()-1, r= str.length()-1;
    int mxLen= -1;

    set<int> st;
    while(l>=0){
        if(!st.count(str[l])){
            st.insert(str[l]);
            continue;
        } else{

        }

    }
    */

    int i=0,j=0;
    int longest=0;          // pwwkew

    vector<int> arr(26,0);

    while(j<str.size())
    {
        while(i<j && arr[str[j]-'a']) {
            arr[str[i]-'a']--;
            i++;
        }
        if(!arr[str[j]-'a']) arr[str[j]-'a']=1;

        longest=max(longest, j-i+1);

        j++;
        //cout<<i<<" "<<j<<endl;
    }

    return longest;
}

int pickToys(vector<char>& toys, int k){
    int mxToys= 0;
    int l= 0, r= 0;
    unordered_map<char, int> freq;
    while(r<toys.size()){
        freq[toys[r]]+=1;
        while(freq.size()>k){
            freq[toys[l]]-=1;
            if(freq[toys[l]]==0) freq.erase(toys[l]);
            l++;
        }
        mxToys= max(mxToys, r-l+1);
        r++;
    }
    return mxToys;
}

// bool atleast(vector<int>& freq, vector<int>& originalFreq){
//     for(int i=0;i<26;i++) if(freq[i]<originalFreq[i]) return false;
//     return true;
// }

// int minWindowSubstring(string s, string t){
//     int l= 0, r= 0;
//     int mnLen= INT32_MAX;
//     string answer= "";

//     vector<int> originalFreq(26, 0);
//     for(char ch: t) originalFreq[ch-'a']+=1;

//     vector<int> freq(26, 0);
//     while(r<s.length()){
//         freq[s[r++]-'a']+=1;
//         if(!atleast(freq, originalFreq)) continue;

//         do{
//             if(r-l<mnLen)
//             {
//                 answer=s.substr(l,r-l);
//                 mnLen=r-l;
//             }
//             freq[s[l++]-'a']-=1;
//         } while(atleast(freq, originalFreq));   
//     }

//     cout<< answer<< " ";
//     return mnLen;
// }

long long powerMod(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
}

int factorial(int n){
    if(n==0) return 1;
    int fact= 1;
    for(int i=n;i>=1;i--) fact*=i;
    return fact;
}

// int getNumPermutations(string& word){
//     vector<int> freq(26, 0);
//     for(char ch: word) freq[ch-'a']+=1;

//     // apply formula of permutation
//     int permutes= factorial(word.length());
//     for(int i=0;i<26;i++){
//         // permutes/= factorial(freq[i]);
//         permutes= permutes * powerMod(factorial(freq[i], MOD-2, MOD))
//     }
//     return permutes;
// }

// int countAnagrams(string s){
//     vector<string> words;
//     int l= 0, r= 0;
//     for(r;r<s.length();r++) if(s[r]==' ') words.push_back(s.substr(l, r-l)), l= r+1;
//     words.push_back(s.substr(l, r-l));

//     int anagrams= 1;
//     for(string word: words) anagrams*= getNumPermutations(word);
//     return anagrams;
// }

bool atleast(unordered_map<char, int>& freq, unordered_map<char, int>& originalFreq){
    for(int i=0;i<26;i++) if(freq[i+'a']<originalFreq[i+'a'] or freq[i+'A']<originalFreq[i+'A']) return false;
    return true;
}

string minWindow(string s, string t){
    int l= 0, r= 0;
    int mnLen= INT32_MAX;
    string answer= "";

    unordered_map<char, int> originalFreq;
    for(char ch: t) originalFreq[ch]+=1;

    unordered_map<char, int> freq;
    while(r<s.length()){
        freq[s[r++]]+=1;
        if(!atleast(freq, originalFreq)) continue;

        do{
            if(r-l<mnLen){
                answer=s.substr(l,r-l);
                mnLen=r-l;
            }
            freq[s[l++]]-=1;
        } while(atleast(freq, originalFreq));   
    }
    return answer;
}

bool isSatisfy(vector<int>& freq, int k){
    // checks whether freq of each `available` char is greater than k
    for(int ele: freq) if(ele!=0 and ele<k) return false;
    return true;
}

int longestSubstring(string s, int k){
    if(s.length()==0) return 0;
    if(k>s.length()) return 0;
    if(k==1) return s.length();

    unordered_map<char, int> freq;
    for(char ch: s) freq[ch]+=1;
    
    int ptr= 0;
    while(freq[s[ptr]]>=k) ptr++; 
    int l1= longestSubstring(s.substr(0, ptr), k);

    while(freq[s[ptr]]<k) ptr++;
    int l2= longestSubstring(s.substr(ptr), k);

    return max(l1, l2);
}

bool isSatisfy(vector<int>& freq, int k){
    // total freq sum - maxFreq should be <= k
    int maxFreq= 0;
    int sum= 0;
    for(int i=0;i<26;i++) maxFreq= max(maxFreq, freq[i]), sum+= freq[i];
    return sum-maxFreq <= k;
}

int characterReplacement(string s, int k){
    int l= 0, r= 0;
    vector<int> freq(26, 0);

    int mxLen= 0;
    while(r<s.length()){
        freq[s[r]-'A']+=1;
        if(isSatisfy(freq, k)){
            mxLen= max(mxLen, r-l+1);
            r+=1;
        } else{
            while(!isSatisfy(freq, k)){
                freq[s[l]-'A']-=1;
                l++;
            }
            r++;
        }
    }
    return mxLen;
}

vector<int> findAnagrams(string s, string p){
    vector<int> indices;
    int k= p.length();

    vector<int> freq(26, 0);
    // store the actual frequency of the p
    vector<int> originalFreq(26, 0);
    for(char ch: p) originalFreq[ch-'a']+=1;

    deque<int> dq;
    // check for the first `k` elements
    int i= 0;
    for(i;i<k;i++) freq[s[i]-'a']+= 1, dq.push_back(i);
    if(freq==originalFreq) indices.push_back(dq.front());

    // slide the window for rest of the elements
    while(i<s.length()){
        freq[s[dq.front()]]-= 1;
        dq.pop_front();

        freq[s[i]-'a']+= 1;
        dq.push_back(i);

        if(freq==originalFreq) indices.push_back(dq.front());
        i+=1;
    }
    return indices;
}

bool checkInclusion(string s1, string s2){
    int k= s1.length();
    if(k>s2.length()) return false;

    // store the original freq of s1
    vector<int> originalFreq(26, 0);
    for(char ch: s1) originalFreq[ch-'a']+=1;

    vector<int> freq(26, 0);
    deque<int> dq;
    int i= 0;
    for(i;i<k;i++) dq.push_back(i), freq[s2[i]-'a']+=1;
    if(freq==originalFreq) return true;

    // slide the window to check for rest of substrings of length `k`
    while(i<s2.length()){
        freq[s2[dq.front()-'a']]-=1;
        dq.pop_front();

        dq.push_back(i);
        freq[s2[i]-'a']+=1;

        if(freq==originalFreq) return true;
        i+=1;
    }
    return false;
}

int lowerbound(vector<int>& arr, int x){ // last element whhich is less-than-equal to than x
    int l= 0, r= arr.size()-1;
    int candidate= -1;

    while(l<=r){
        int mid= (l+r)/2;
        if(arr[mid]<=x) candidate= mid, l= mid+1;
        else r= mid-1;
    }
    return candidate;
}

int upperbound(vector<int>& arr, int x){ // first element whhich is greater-than-equal to than x
    int l= 0, r= arr.size()-1;
    int candidate= -1;

    while(l<=r){
        int mid= (l+r)/2;
        if(arr[mid]>=x) candidate= mid, r=mid-1;
        else l= mid+1;
    }
    return candidate;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x){
    // find the closest element's index to `x` using Binary Search
    int closestL= lowerbound(arr, x);
    int closestU= upperbound(arr, x);

    int closest;
    if(closestL==-1) closest= closestU;
    else if(closestU==-1) closest= closestL;
    else{
        if(abs(arr[closestL]-x)<abs(arr[closestU]-x)) closest= closestL;
        else if(abs(arr[closestL]-x)>abs(arr[closestU]-x)) closest= closestU;
        else closest= arr[closestL]<=arr[closestU] ? closestL : closestU;
    }

    vector<int> answer;
    answer.push_back(arr[closest]);
    // expand in the left and right side of closest
    int l= closest-1, r= closest+1;
    while(l>=0 and r<arr.size() and answer.size()<k){
        if(abs(arr[l]-x)<=abs(arr[r]-x)) answer.push_back(arr[l--]);
        else answer.push_back(arr[r++]);
    }
    while(l<0 and answer.size()<k) answer.push_back(arr[r++]);
    while(r==arr.size() and answer.size()<k) answer.push_back(arr[l--]);

    sort(answer.begin(), answer.end());
    return answer;
}

int findLength(vector<int>& nums1, vector<int>& nums2){ // https://youtu.be/hj-HDHwifWs
    int l1= nums1.size(), l2= nums2.size();
    vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0)); // each element of the matrix tells us the longest common substring ending at that particular position`s`

    int mxLen= 0;
    for(int i=1;i<=l1;i++)
        for(int j=1;j<=l2;j++)
            if(nums1[i-1]==nums2[j-1]) dp[i][j]= dp[i-1][j-1]+1, mxLen= max(mxLen, dp[i][j]);
    return mxLen;
}

int upperbound(vector<int>& prefixSum, int x, int limit){
    int l= 0, r= limit-1;
    int candidate= -1;
    while(l<=r){
        int mid= (l+r)/2;
        if(prefixSum[mid]<=x) candidate= mid, l= mid+1;
        else r= mid-1;
    }
    return candidate;
}

int shortestSubarray(vector<int>& nums, int k){
    vector<int> prefixSum(nums.size(), 0);
    prefixSum[0]= nums[0];
    if(nums[0]>=k) return 1;

    int mnLen= INT32_MAX;
    for(int i=1;i<nums.size();i++){
        prefixSum[i]= prefixSum[i-1]+nums[i];
        if(prefixSum[i]>=k) mnLen= min(mnLen, i+1);
        int rem= prefixSum[i]-k;
        // we have to remove the longest subarray(ending idx less than i) having sum <=rem
        int remSumSubarrayIdx= upperbound(prefixSum, rem, i);
        if(remSumSubarrayIdx!=-1) mnLen= min(mnLen, i-remSumSubarrayIdx);  
    }
    return mnLen;
}

int caseA(vector<int>& arr, int l){
    int k= l;
    while(k<arr.size()-1 and ((k%2==0 and arr[k]>arr[k+1]) or (k%2==1 and arr[k]<arr[k+1]))) k++;
    return k-l+1;
}

int caseB(vector<int>& arr, int l){
    int k= l;
    while(k<arr.size()-1 and ((k%2==1 and arr[k]>arr[k+1]) or (k%2==0 and arr[k]<arr[k+1]))) k++;
    return k-l+1;
}

int maxTurbulenceSize(vector<int>& arr){
    if(arr.size()==1) return 1;

    int l= 0, l1, l2;
    int mxLen= 0;
    while(l<arr.size()-1){
        if(arr[l]==arr[l+1]){
            l++;
        } else{
            if(
            (l%2==0 and arr[l]>arr[l+1]) or  
            (l%2==1 and arr[l]<arr[l+1])
            ){
                l1= caseA(arr, l);
                mxLen= max(mxLen, l1);
                l= l+l1-1;
            } else if(
                (l%2==1 and arr[l]>arr[l+1]) or
                (l%2==0 and arr[l]<arr[l+1])
            ){
                l2= caseB(arr, l);
                mxLen= max(mxLen, l2);
                l= l+l2-1;
            }
        }
    }
    return mxLen;
}

bool helper(vector<int>& nums, vector<vector<int>>& dp, int target, int curr){
    if(target==0) return true;
    if(target<0) return false;
    if(curr>=nums.size()) return false;
    if(dp[curr][target]!=-1) return dp[curr][target];

    // if we take current element
    bool flag1= helper(nums, dp, target-nums[curr], curr+1);
    // if we donot take current element
    bool flag2= flag1 ? false : helper(nums, dp, target, curr+1);

    return dp[curr][target]= flag1 or flag2;
}

bool canPartition(vector<int>& nums){
    // total sum must be even
    // we need to find the subset having sum equals total_sum/2
    int total_sum= 0;
    for(int ele: nums) total_sum+= ele;
    if(total_sum%2==1) return false;

    vector<vector<int>> dp(nums.size(), vector<int>(total_sum/2 + 1, -1));
    bool isPossible= helper(nums, dp, total_sum/2, 0); // 0 -> initial index
    return isPossible;
}

int check(vector<int>& nums, vector<vector<int>>& dp, int target, int count= 0, int curr= 0){
    if(target==0) return count;
    if(curr>=nums.size()) return count;
    if(dp[curr][target]!=-1) return dp[curr][target];

    // if we take current element
    // int len1= check(nums, dp, target-nums[curr], lenSubset+1, curr+1);
    // if we donot take current element
    // int len2= len1 ? 0 : check(nums, dp, target, lenSubset, curr+1);

    // return dp[curr][target]= flag1 or flag2;
}

void recursion(vector<int>& nums, map<vector<int>, int>& dp, int& mnDiff, int curr_idx, int n, const int& total_sum, int curr_sum= 0){
    if(n==0){
        mnDiff= min(mnDiff, total_sum-2*curr_sum);
        return;
    }
    if(curr_idx>=nums.size()) return;
    if(dp.count({curr_idx, n, curr_sum})!=0){
        mnDiff= min(mnDiff, dp[{curr_idx, n, curr_sum}]);
        return;
    }

    // if we choose the curr element
    recursion(nums, dp, mnDiff, curr_idx+1, n-1, total_sum, curr_sum+nums[curr_idx]);
    // if we do not choose the curr element
    recursion(nums, dp, mnDiff, curr_idx+1, n, total_sum, curr_sum);
    dp[{curr_idx, n, curr_sum}]= mnDiff;
}

int minimumDifference(vector<int>& nums){
    int n= nums.size()/2;
    map<vector<int>, int> dp;

    int total_sum= 0;
    for(int ele: nums) total_sum+= ele;
    
    int mnDiff= INT32_MAX;
    recursion(nums, dp, mnDiff, 0, n, total_sum);
    return mnDiff;
}

int helper(vector<int>& nums, map<pair<int, int>, int>& dp, int target, int curr){
    if(curr==nums.size() and target==0) return 1;
    if(curr==nums.size() and target!=0) return 0;
    if(dp.count({curr, target})!=0) return dp[{curr, target}];

    int ways1= helper(nums, dp, target-nums[curr], curr+1); // take element with `+` sign
    int ways2= helper(nums, dp, target+nums[curr], curr+1); // take element with `-` sign

    return dp[{curr, target}]= ways1+ways2;
}

int findTargetSumWays(vector<int>& nums, int target){
    map<pair<int, int>, int> dp;
    int total_ways= helper(nums, dp, target, 0);
    return total_ways;
}

int helper(vector<int>& coins, vector<int>& dp, int amount){
    if(amount==0) return 1;
    if(dp[amount]!=-1) return dp[amount];

    int total_ways= 0;
    for(int coin: coins){
        if(amount-coin<0) continue;
        int ways= helper(coins, dp, amount-coin);
        total_ways+= ways;
    }
    return dp[amount]= total_ways;
}

int change(int amount, vector<int>& coins){
    vector<int> dp(amount+1, -1);
    return helper(coins, dp, amount);
}

bool isPalindrome(string& str){
    string rev_str= str;
    reverse(rev_str.begin(), rev_str.end());
    if(str!=rev_str) return false;
    return true;
}

void helper(string str, vector<string>& substrings, vector<vector<string>>& answer, unordered_map<string, vector<vector<string>>>& dp){
    if(isPalindrome(str)){
        substrings.push_back(str);
        answer.push_back(substrings);
        substrings.pop_back();
        return;
    }
    if(dp.count(str)!=0){
        for(vector<string> v: dp[str]){
            v.insert(v.begin(), substrings.begin(), substrings.end());
            answer.push_back(v);
        }
        return;
    }

    for(int i=0;i<str.length()-1;i++){
        string substr= str.substr(0, i+1);
        if(!isPalindrome(substr)) continue;

        substrings.push_back(substr);
        helper(str.substr(i+1), substrings, answer, dp);
        substrings.pop_back();
    }
    dp[str]= answer;
}

vector<vector<string>> partition(string s){
    vector<string> substrings;
    vector<vector<string>> answer;
    unordered_map<string, vector<vector<string>>> dp;
    helper(s, substrings, answer, dp);
    return answer;
}

int helper(vector<int>& nums, int i, int j){
    if(i>j) return 0;

    int product= 1;
    int mxProduct= INT32_MIN;
    for(int ptr=i;ptr<=j;ptr++) product*= nums[ptr], mxProduct= max(mxProduct, product);


    while(i<j){
        product/= nums[i];
        mxProduct= max(mxProduct, product);
        i++;
    }
    return mxProduct;
}

int maxProduct(vector<int>& nums){
    deque<int> dq;
    for(int i=0;i<nums.size();i++) if(nums[i]==0) dq.push_back(i);
    dq.push_front(-1), dq.push_back(nums.size());

    int mxProduct= INT32_MIN;
    while(dq.size()>1){
        int i= dq.front()+1;
        dq.pop_front();
        int j= dq.front()-1;
        mxProduct= max(mxProduct, helper(nums, i, j));
    }
    return mxProduct;
}

int maxProfit(vector<int>& prices){
    vector<int> maxFrom(prices.size(), -1); // maxFrom[i] : maxm element starting from ith index in prices
    maxFrom[prices.size()-1]= prices[prices.size()-1];

    for(int i=prices.size()-2;i>=0;i--) maxFrom[i]= max(prices[i], maxFrom[i+1]);

    int mxProfit= 0;
    for(int i=0;i<prices.size();i++){
        int buyPrice= prices[i];
        mxProfit= max(mxProfit, maxFrom[i]-buyPrice);
    }
    return mxProfit;
}

int maxProfit(vector<int>& prices){
    // best way to maximize the profit is to buy at the local minima and to sell at the local maxima
    int l= 0, r;
    int total_profit= 0;
    while(l<prices.size()-1){
        int tmpProfit= 0;
        while(l<prices.size()-1 and prices[l]>prices[l+1]) l++;
        if(l>=prices.size()-1) break;

        r= l+1;
        while(r<prices.size()-1 and prices[r]<prices[r+1]) r++;
        tmpProfit= prices[r]-prices[l]; // buy at l sell at r
        total_profit+= tmpProfit;
        l= r+1;
    } 
    return total_profit;
}

bool isPalindrome(string& str, int l, int r){
    string s1, s2;
    s1= s2= str.substr(l, r-l+1);
    reverse(s2.begin(), s2.end());
    return s1==s2;
}

int minCut(string s){
    // tabular method
    vector<vector<bool>> palindrome(s.length(), vector<bool>(s.length(), false)); // palindrome[i][j] : whether substring betn i to j is palindrome or not
    for(int i=0;i<palindrome.size();i++) for(int j=0;j<palindrome[i].size();j++) palindrome[i][j]= isPalindrome(s, i, j);

    vector<int> dp(s.length(), -1); // dp[i] : minimum cuts required for string upto index i
    for(int i=0;i<dp.size();i++){
        if(palindrome[0][i]){
            dp[i]= 0;
            continue;
        }

       dp[i]= i;
       for(int j=0;j<i;j++) if(palindrome[j+1][i]) dp[i]= min(dp[i], 1+dp[j]);
    }
    return dp[s.length()-1];
}

int maxProfit(vector<int>& prices){
    int mxProfit, secondMxProfit;
    mxProfit= secondMxProfit= INT32_MIN;

    int l= 0, r;
    int n= prices.size();
    while(l<n-1){
        while(l<n-1 and prices[l]>=prices[l+1]) l++;

        r= l+1;
        while(r<n-1 and prices[r]<=prices[r+1]) r++;

        int curr_profit= prices[r]-prices[l];
        if(curr_profit>mxProfit){
            secondMxProfit= mxProfit;
            mxProfit= curr_profit;
        } else if(curr_profit>secondMxProfit){
            secondMxProfit= curr_profit;
        }
        l= r+1;
    }

    int totalProfit= 0;
    totalProfit+= (mxProfit==INT32_MIN ? 0 : mxProfit) + (secondMxProfit==INT32_MIN ? 0 : secondMxProfit);
    return totalProfit;
}

int maximalSquare(vector<vector<char>>& matrix){
    int m= matrix.size();
    int n= matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    // fill the last row and the last column
    for(int j=0;j<n-1;j++) dp[m-1][j]= matrix[m-1][j];
    for(int i=0;i<m;i++) dp[i][n-1]= matrix[i][n-1];

    int mxSize= INT32_MIN;
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]= 1 + min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));
            mxSize= max(mxSize, dp[i][j]);
        }
    }

    return mxSize*mxSize;
}

int helper(vector<int>& prices, vector<int>& dp, int start){
    if(start>=prices.size()) return 0;
    if(dp[start]!=-1) return dp[start];
    
    int mxProfit= 0;
    int l= start;
    while(l<prices.size()-1 and prices[l]>=prices[l+1]) l++;
    if(l==prices.size()-1) return 0;

    int r= l+1;
    while(r<prices.size() and prices[l]<prices[r]){
        int currentProfit= prices[r]-prices[l];
        int postMaxProfit= helper(prices, dp, r+2);
        mxProfit= max(mxProfit, currentProfit+postMaxProfit);
        r++;
    }
    
    mxProfit= max(mxProfit, helper(prices, dp, r));
    return dp[start]= mxProfit;
}

int maxProfit(vector<int>& prices){
    vector<int> dp(prices.size(), -1);
    return helper(prices, dp, 0);
}

vector<vector<int>> generate(int numRows){
    vector<vector<int>> pascalsTriangle(numRows);
    for(int i=0;i<numRows;i++){
        vector<int> row(i+1, 1);
        for(int j=1;j<row.size()-1;j++)
            row[j]= pascalsTriangle[i-1][j]+pascalsTriangle[i-1][j-1];
        pascalsTriangle[i]= row;
    }
    return pascalsTriangle;
}

int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int row= 0, int col= 0){
    if(row>=triangle.size()) return 0;
    if(col>=triangle[row].size()) return INT32_MAX;
    if(dp[row][col]!=-1) return dp[row][col];

    int totalSum= triangle[row][col];
    int postSum1= helper(triangle, dp, row+1, col);
    int postSum2= helper(triangle, dp, row+1, col+1);
    totalSum+= min(postSum1, postSum2);
    return dp[row][col]= totalSum;
}

int minimumTotal(vector<vector<int>>& triangle){
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size(), -1));
    return helper(triangle, dp);
}

int eraseOverlapIntervals(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end());
    int prevEndVal= intervals[0][1];
    int popOuts= 0;
    for(int i=1;i<intervals.size();i++){
        if(intervals[1][0]<prevEndVal){
            popOuts++;
            prevEndVal= min(prevEndVal, intervals[i][1]);
            continue;
        }
        prevEndVal= intervals[i][1];
    } 
    return popOuts;
}

int sum_total(vector<int>& dp){
    int sum= 0;
    for(int i=0;i<dp.size();i++) sum+= dp[i];
    return sum;
}

int countNumbersWithUniqueDigits(int n){
    vector<int> dp(n+1, 0);
    dp[1]= 10;
    for(int i=2;i<=n;i++){
        dp[i]= 9;
        int ways= 9;
        for(int spot=i-1;spot>=1;spot--) dp[i]*= ways, ways--;
    }

    int total_unique_digits_numbers= sum_total(dp);
    int total_numbers= pow(10, n);
    return total_numbers-total_unique_digits_numbers;
}

int countOnes(int x){
    int count= 0;
    while(x>0) count+= x&1, x>>1;
    return count;
}

vector<int> countBits(int n){
    vector<int> numOnes(n+1);
    for(int i=0;i<=n;i++) numOnes[i]= countOnes(i);
    return numOnes;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    int m= mat.size();
    int n= mat[0].size();
    vector<vector<int>> answer(m, vector<int>(n, 0));
    queue<tuple<int, int, int>> q; 

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(mat[i][j]==0) q.push(make_tuple(i, j, 0));
        
    while(!q.empty()){
        int i= get<0>(q.front());
        int j= get<1>(q.front());
        int dist_of_nearest_zero= get<2>(q.front());

        int x, y;
        if(i+1<m and mat[i+1][j]==1 and answer[i+1][j]==0){
            x= i+1, y= j;
            answer[x][y]= dist_of_nearest_zero+1;
            q.push(make_tuple(x, y, answer[x][y]));
        }     
        if(j+1<n and mat[i][j+1]==1 and answer[i+1][j]==0){
            x= i, y= j+1;
            answer[x][y]= dist_of_nearest_zero+1;
            q.push(make_tuple(x, y, answer[x][y]));
        }
        if(i-1>=0 and mat[i-1][j]==1 and answer[i+1][j]==0){
            x= i-1, y= j;
            answer[x][y]= dist_of_nearest_zero+1;
            q.push(make_tuple(x, y, answer[x][y]));
        }
        if(j-1>=0 and mat[i][j-1]==1 and answer[i+1][j]==0){
            x= i, y= j-1;
            answer[x][y]= dist_of_nearest_zero+1;
            q.push(make_tuple(x, y, answer[x][y]));
        }
        
        q.pop();
    }

    return answer;
}

int minFlips(int a, int b, int c){
    int flips= 0;
    while(a!=0 and b!=0 and c!=0){
        int lsb_a= a bitand 1;
        int lsb_b= b bitand 1;
        int lsb_c= c bitand 1;

        if(((lsb_a  bitor lsb_b) == 0) and lsb_c==1) flips+=1;
        else if(((lsb_a  bitor lsb_b) == 1) and lsb_c==0) flips+= lsb_a + lsb_b;

        a= a>>1;
        b= b>>1;
        c= c>>1;
    }
    return flips;
}

// TRIEs

class Node{
public:
    vector<Node*> children;
    bool eow; // End Of Word

    Node(){
        children.resize(26, nullptr);
        eow= false;
    }
};

class Trie{
public:
    Node* root;

    Trie(){
        root= new Node(); // create an empty root
    }
};

void insertInTrie(Node* root, string word){ // O(L)
    for(int i=0;i<word.length();i++){
        int idx= word[i]-'a';
        if(root->children[idx] == nullptr) root->children[idx]= new Node();
        root= root->children[idx];
    }
    root->eow= true;
}

string getSmallestPrefix(string& word, Node* root, int start= 0){
    if(start>=word.length()) return word;

    int idx= word[start]-'a';
    if(root->children[idx]==nullptr) return word;
    if(root->children[idx]->eow) return word.substr(0, start+1);
    return getSmallestPrefix(word, root->children[idx], start+1);
}

string replaceWords(vector<string>& dictionary, string sentence){
    // insert all the words of dictionary in a TRIE
    // for every word in sentance
    // search wheter its prefix exist in the dictionary or not
    // if yes replace word with that prefix

    Trie trie;
    for(int i=0;i<dictionary.size();i++) insertInTrie(trie.root, dictionary[i]);

    int l= 0, r= 0;
    sentence.push_back(' ');
    while(r<sentence.length()){
        while(sentence[r]!=' ') r++;
        string word= sentence.substr(l, r-l);
        string smallest_prefix_present= getSmallestPrefix(word, trie.root);
        sentence.replace(l, r-l, smallest_prefix_present);

        l= r= l+smallest_prefix_present.length()+1;
    }
    sentence.pop_back();
    return sentence;
}

bool isPrefixAndSuffix(string& str1, string& str2){
    if(str1.length()>str2.length()) return false;
    return str1==str2.substr(0, str1.length()) and str1==str2.substr(str2.length()-str1.length());
}

int countPrefixSuffixPairs(vector<string>& words){
    int count= 0;
    for(int i=0;i<words.size();i++)
        for(int j=i+1;j<words.size();j++)
            if(isPrefixAndSuffix(words[i], words[j])) count++;
        
    return count;
}

void order_util(Node* root, vector<int>& lexical, string curr= ""){
    for(int i=0;i<=9;i++){
        if(root->children[i]==nullptr) continue;

        curr.push_back('0'+i);
        lexical.push_back(stoi(curr));
        order_util(root->children[i], lexical, curr);
        curr.pop_back();
    }
}

vector<int> lexicalOrder(int n){
    // insert all the numbers as strings in TRIE
    Trie trie;
    for(int i=1;i<=n;i++) insertInTrie(trie.root, to_string(i));

    vector<int> lexical;
    order_util(trie.root, lexical);
}

vector<string> topKFrequent(vector<string>& words, int k){
    unordered_map<string, int> str_freq;
    for(string word: words) str_freq[word]+= 1;
    
    map<int, vector<string>, greater<int>> freq_str;
    for(pair<string, int> p: str_freq)
        freq_str[p.second].push_back(p.first);
    
    vector<string> answer;
    for(pair<int, vector<string>> p: freq_str){
        if(p.second.size()>1) sort(p.second.begin(), p.second.end());
        int i= 0;
        while(answer.size()<k and i<p.second.size()) answer.push_back(p.second[i++]);
        if(answer.size()>=k) break;
    }
    return answer;
}

int lengthOfLongestSubstring(string s){
    deque<char> dq;
    unordered_map<char, int> freq;
    int mxLen= 0;

    for(int i=0;i<s.length();i++){
        dq.push_back(s[i]);
        freq[s[i]]+= 1;
        
        bool isUnique= freq[s[i]]==1;
        if(isUnique){
            int dqSize= dq.size();
            mxLen= max(mxLen, dqSize);
        } else{
            while(freq[s[i]]>1){
                freq[dq.front()]-= 1;
                dq.pop_front();
            }
        }
    }
    return mxLen;
}

int minAreaRect(vector<vector<int>>& points){
    int mnArea= INT32_MAX;
    for(int i=0;i<points.size()-3;i++){
        if(points[i][0]!=points[i+1][0]) continue;
        for(int j=i+2;j<points.size()-1;j++){
            if(points[j][0]!=points[j+1][0] or points[i][1]!=points[j][1] or points[i+1][1]!=points[j+1][1]) continue;
            int newArea= (points[j][0]-points[i][0])*(points[i+1][1]-points[i][0]);
            mnArea= min(mnArea, newArea);
            break;
        }
    }
    return mnArea==-1 ? 0 : mnArea;
}

void helper(vector<int>& candidates, vector<vector<int>>& answer, vector<int>& combination, int target, int s= 0){
    if(target<0) return;
    if(target==0){
        answer.push_back(combination);
        return;
    }

    for(int i=s;i<candidates.size();i++){
        combination.push_back(candidates[i]);
        helper(candidates, answer, combination, target-candidates[i], i+1);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    vector<vector<int>> answer;
    vector<int> combination;
    helper(candidates, answer, combination, target);
    return answer;
}

int numberOfSubmatrices(vector<vector<char>>& grid){
    int m= grid.size(), n= grid[0].size();
    vector<vector<pair<int, int>>> prefixCount(m, vector<pair<int, int>>(n, {0, 0}));
    // calculate row wise
    for(int i=0;i<m;i++){
        if(grid[i][0]=='x') prefixCount[i][0].first= 1;
        else prefixCount[i][0].second= 1;
        for(int j=1;j<n;j++){
            prefixCount[i][j].first= prefixCount[i][j-1].first + grid[i][j]=='x' ? 1 : 0;
            prefixCount[i][j].second= prefixCount[i][j-1].second + grid[i][j]=='y' ? 1 : 0;
        } 
    }
    // calculate column wise
    for(int j=0;j<n;j++){
        for(int i=1;i<m;i++){
            prefixCount[i][j].first+= prefixCount[i-1][j].first;
            prefixCount[i][j].second+= prefixCount[i-1][j].second;
        }
    }

    int submatrices= 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int x= prefixCount[i][j].first;
            int y= prefixCount[i][j].second;
            if(x==y and x>=1) submatrices+= 1;
        }
    }
        
    return submatrices;
}

long long maxPoints(vector<vector<int>>& points){
    int m= points.size(), n= points[0].size();
    vector<long long> prevRow(n);
    for(int j=0;j<n;j++) prevRow[j]= points[0][j];

    vector<long long> left(n), right(n);
    for(int i=1;i<m;i++){
        // calculate left and right for the prevRow
        left[0]= prevRow[0];
        for(int j=1;j<n;j++) left[j]= max(prevRow[j], left[j]-1);

        right[n-1]= prevRow[n-1];
        for(int j=n-2;j>=0;j--) right[j]= max(prevRow[j], right[j+1]-1);

        // update prevRow for the curr row
        for(int j=0;j<n;j++) prevRow[j]= max(left[j], right[j]) + points[i][j];
    }

    // return max of prevRow
    long long mxPoints= 0;
    for(int j=0;j<n;j++) mxPoints= max(mxPoints, prevRow[j]);
    return mxPoints;
}

int maxScoreSightseeingPair(vector<int>& values){
    // mximize: values[j]+values[i] - (j-i)
    // maximize: (values[j]-j) + values[i]+i
    // for a given `j` choose the best `i` till the posn `j-1` as i<j

    int mxScore= INT32_MIN;
    int bestTill= values[0]+0;
    for(int j=1;j<values.size();j++){
        mxScore= max(mxScore, values[j]-j + bestTill);
        bestTill= max(bestTill, values[j]+j);
    }
    return mxScore;
}

int nthUglyNumber(int n){
    vector<int> uglyNumbers;
    uglyNumbers.push_back(1);

    int i2= 0, i3= 0, i5= 0;
    while(uglyNumbers.size()<n){
        int nextUglyNumber= min(uglyNumbers[i2]*2, min(uglyNumbers[i3]*3, uglyNumbers[i5]*5));
        uglyNumbers.push_back(nextUglyNumber);

        if(uglyNumbers[i2]*2 == nextUglyNumber) i2++;
        if(uglyNumbers[i3]*3 == nextUglyNumber) i3++;
        if(uglyNumbers[i5]*5 == nextUglyNumber) i5++;
    }
    return uglyNumbers.back();
}

int recursion(string str, string clipboard, int n, vector<int>& dp, int steps= 0){
    if(str.length()>n) return INT32_MAX;
    if(str.length()==n) return steps;
    if(dp[str.length()]!=-1) return dp[str.length()];

    // paste the string present at the clipboard
    int op1= clipboard!="" ? recursion(str+clipboard, clipboard, n, dp, steps+1) : INT32_MAX;
    // copy only if not already copied
    int op2= clipboard!=str ? recursion(str, str, n, dp, steps+1) : INT32_MAX;
    steps= min(op1, op2);
    return dp[str.length()]= steps;
}

int minSteps(int n){
    if(n==1) return 0;

    string str= "A";
    string clipboard= "";
    vector<int> dp(n+1, -1);
    int minOperations= recursion(str, clipboard, n, dp);
    return minOperations;
}

void visit_util(vector<vector<int>>& rooms, vector<bool>& isVisited, int room_no){
    if(isVisited[room_no]) return;
    // mark visited the curr room
    isVisited[room_no]= true; 
    // insert the children of the curr room
    for(int key: rooms[room_no])
        visit_util(rooms, isVisited, key);
}

bool canVisitAllRooms(vector<vector<int>>& rooms){
    int n= rooms.size();
    vector<bool> isVisited(n, false);
    visit_util(rooms, isVisited, 0);
    // check if all the rooms are visited or not
    for(int i=0;i<n;i++) if(!isVisited[i]) return false;
    return true;
}

class DSU{
public: 
    map<vector<int>, vector<int>> parent;
    map<vector<int>, int> size;

    void make(vector<int>& cell){
        parent[cell]= cell;
        size[cell]= 1;
    }

    vector<int> find(vector<int>& cell){
        if(parent[cell]==cell) return cell;
        return parent[cell]= find(parent[cell]);
    }

    void union_(vector<int> cell1, vector<int> cell2){
        cell1= find(cell1);
        cell2= find(cell2);
        if(cell1==cell2) return;
        if(size[cell1]<size[cell2]) swap(cell1, cell2);
        parent[cell2]= cell1;
        size[cell1]+= size[cell2];
    }
};

class Solution{
public:
    int removeStones(vector<vector<int>>& stones){
        DSU dsu;
        for(vector<int> stone: stones) dsu.make(stone);

        for(int i=0;i<stones.size();i++)
            for(int j=i+1;j<stones.size();j++)
                if(stones[j][0]==stones[i][0] or stones[j][1]==stones[i][1])
                    dsu.union_(stones[i], stones[j]);

        int removed_stones= 0;
        set<vector<int>> deleted_roots;
        for(int i=0;i<stones.size();i++){
            vector<int> root= dsu.find(stones[i]);
            if(deleted_roots.count(root)!=0) continue;
            
            deleted_roots.insert(root);
            removed_stones+= dsu.size[root]-1;
        }
        return removed_stones;
    }
};

double dijkstra(vector<vector<pair<int, int>>>& graph, int n, int src, int dest){
    vector<double> prob(n, 0);
    vector<bool> isVisited(n, false);
    priority_queue<pair<double, int>, vector<pair<double, int>>> pq;

    prob[src]= 1;
    pq.push({prob[src], src});
    while(!pq.empty()){
        int par= pq.top().second;
        pq.pop();
        if(isVisited[par]) continue;

        isVisited[par]= true;
        for(pair<int, int> p: graph[par]){
            int child= p.first;
            int edgWt= p.second;
            if(prob[child]<prob[par]*edgWt){
                prob[child]= prob[par]*edgWt;
                pq.push({prob[child], child});
            }
        }
    }
    return prob[dest];
}

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node){
    vector<vector<pair<int, int>>> graph(n);
    for(int i=0;i<n;i++){
        int u= edges[i][0];
        int v= edges[i][1];
        int wt= succProb[i];
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    
    double mxProb= dijkstra(graph, n, start_node, end_node);
    return mxProb;
}

void util(vector<vector<int>>& graph, vector<bool>& isVisited, vector<vector<bool>>& isAncestor, vector<vector<int>>& ancestors, int src){
    if(isVisited[src]) return;

    isVisited[src]= true;
    for(int child: graph[src]){
        util(graph, isVisited, isAncestor, ancestors, child);
        for(int i=0;i<ancestors[child].size();i++){
            if(isAncestor[ancestors[child][i]][src]) continue;
            ancestors[src].push_back(ancestors[child][i]);
            isAncestor[ancestors[child][i]][src]= true;
        }
        if(!isAncestor[child][src]) ancestors[src].push_back(child), isAncestor[child][src]= true;
    }
}

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges){
    vector<vector<bool>> isAncestor(n, vector<bool>(n, false)); // isAncestor[i][j] = whether i is the ancestor of j or not
    vector<vector<int>> graph(n);
    for(vector<int> edge: edges){
        int u= edge[0];
        int v= edge[1];
        // enter reversed edge
        graph[v].push_back(u);
    }

    vector<bool> isVisited(n, false);
    vector<vector<int>> ancestors(n);
    for(int i=n-1;i>=0;i--){
        if(isVisited[i]) continue;
        util(graph, isVisited, isAncestor, ancestors, i);
    }

    for(int i=0;i<ancestors.size();i++) sort(ancestors[i].begin(), ancestors[i].end());
    return ancestors;
}

vector<int> bfs(vector<vector<int>>& graph, int master){
    int n= graph.size();
    vector<bool> isVisited(n, false);
    vector<int> lavel(n, 0);

    queue<int> q;
    q.push(master);
    isVisited[master]= true;
    while(!q.empty()){
        int src= q.front();
        q.pop();
        for(int child: graph[src]){
            if(isVisited[child]) continue;

            isVisited[child]= true;
            q.push(child);
            lavel[child]= lavel[src]+1;
        }
    }
    return lavel;
}

int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience){
    // find the min time taken by message of each node to reach the master server
    // use this time and the patience time of the node to calculate the time at which the node sends its last message
    // total time taken by the node = last message sent time + travel time(node-master + master-node)
    vector<vector<int>> graph;
    for(int i=0;i<edges.size();i++){
        int u= edges[i][0];
        int v= edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> lavel= bfs(graph, 0);

    int n= graph.size();
    int idleTime= 0;
    for(int i=1;i<n;i++){
        int lastMessageSentTime= 0;
        int firstMessageArrivalTime= 2*lavel[i];
        while(lastMessageSentTime+patience[i]<firstMessageArrivalTime) lastMessageSentTime+= patience[i];
        idleTime= max(idleTime, lastMessageSentTime+lavel[i]+1);
    }
    return idleTime;
}

int minGroups(vector<vector<int>>& intervals){
    // train deperture problem
    vector<int> arrivalTime;
    vector<int> depertureTime;
    for(int i=0;i<intervals.size();i++){
        arrivalTime.push_back(intervals[i][0]);
        depertureTime.push_back(intervals[i][1]);
    }
    sort(arrivalTime.begin(), arrivalTime.end());
    sort(depertureTime.begin(), depertureTime.end());

    int arv_ptr= 0;
    int dep_ptr= 0;
    int platforms= 1;
    while(arv_ptr<arrivalTime.size()){
        if(arrivalTime[arv_ptr]<=depertureTime[dep_ptr]){
            platforms++;
            arv_ptr++;
        } else{
            arv_ptr++;
            dep_ptr++;
        }
    }
    return platforms;
}

string decimal2binary(int x){
    if(x==0) return "0";
    string bin= "";
    while(x>1){
        int rem= x%2;
        x/=2;
        bin.append(to_string(rem));
    }
    bin.push_back('1');
    reverse(bin.begin(), bin.end());
    return bin;
}

vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries){
    // if a^b=x then x=a^b
    // a=first_i, b=second_i hence x can be found
    // convert decimal x into binary string
    // find the first occurence of x in the string s
    int n= queries.size();
    vector<vector<int>> answer;

    // push all valid substring of length<=30
    unordered_map<string, pair<int, int>> mp;
    for(int i=0;i<s.length();i++){
        string temp= "";
        for(int j=0;j<30;j++){
            if(i+j>=s.length()) break;
            temp.push_back(s[i+j]);
            if(mp.count(temp)==0) mp[temp]= {i, j};
        }
    }

    for(int i=0;i<n;i++){
        int first= queries[i][0];
        int second= queries[i][1];
        int x= first^second;
        string x_str= decimal2binary(x);

        if(mp.count(x_str)==0) answer.push_back({-1, -1});
        else answer.push_back({mp[x_str].first, mp[x_str].second});
    }
    return answer;
}

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries){
    // to store frequency of each char upto index i we will use a vector 
    int n= s.length();
    vector<vector<int>> freq(n, vector<int>(26, 0));
    freq[0][s[0]-'a']= 1; 
    for(int i=1;i<n;i++) freq[i]= freq[i-1], freq[i][s[i]-'a']+= 1;

    // maximum number of distict character for a palindrome, X = ceil(len/2)
    // therefore, total number of distinct elements - k <= X
    // we will find distinct elements from [l, r] using `freq` vector
    int m= queries.size();
    vector<bool> answer(m, false);
    for(int i=0;i<m;i++){
        int l= queries[i][0];
        int r= queries[i][1];
        int k= queries[i][2];

        int X= ceil((r-l+1)/2.0);
        int numDistinct= 0;
        if(l==0){
            for(int i=0;i<26;i++)
                if(freq[r][i]!=0)
                    numDistinct++;
        } else{
            for(int i=0;i<26;i++)
                if(freq[r][i]-freq[l-1][i]!=0)
                    numDistinct++;
        }
        if(numDistinct-k<=X) answer[i]= true;
    }
    return answer;
}

int maxFreq(string s, int maxLetters, int minSize, int maxSize){
    // if length of the substring is reasonable then we can iterate through every index the count the valid substrings starting from that index
    // here `map` will strore the freq of every valid substring
    // and the one having maxm freq will be our answer substring
    unordered_map<string, int> freq;
    int maxFreq= 0;
    for(int i=0;i<s.length()-minSize+1;i++){
        string interimString= "";
        int uniqueChars= 0, j= 0;
        vector<bool> isOccured(26, false);
        while(i+j<s.length() and j<maxSize and uniqueChars<=maxLetters){
            if(!isOccured[s[i+j]-'a']){
                isOccured[s[i+j]-'a']= true;
                uniqueChars+= 1;
                if(uniqueChars>maxLetters) break;
            }

            interimString.push_back(s[i+j]);
            if(interimString.length()<minSize){
                j+= 1;
                continue;
            }

            freq[interimString]+= 1;
            maxFreq= max(maxFreq, freq[interimString]);
            j+= 1;
        }
    }
    return maxFreq;
}

int maximumCostSubstring(string s, string chars, vector<int>& vals){
    // set value of every character
    vector<int> value(26);
    for(int i=0;i<26;i++) value[i]= i+1;
    for(int i=0;i<chars.length();i++) value[chars[i]-'a']= vals[i];

    // discard the substring having negative cost
    int mxCost= 0, interimCost= 0;
    deque<char> dq;
    for(int i=0;i<s.length();i++){
        dq.push_back(s[i]);
        interimCost+= value[s[i]-'a'];
        while(interimCost<0)
            interimCost-= value[dq.front()-'a'], dq.pop_front();
        mxCost= max(mxCost, interimCost);
    }
    return mxCost;
}

bool sameFreq(vector<int>& freq){
    int f= -1;
    for(int i=0;i<26;i++){
        if(freq[i]==0) continue;
        if(f==-1) f= freq[i];
        if(f!=freq[i]) return false;
    }
    return true;
}

int countUtil(string& str, vector<int>& dp, int l){
    if(l>=str.length()) return 0;
    if(dp[l]!=-1) return dp[l];

    // find every index(breaking point) upto which the frequency of every char present is same
    // if min freq upto `i` = max freq upto `i` 
    vector<int> freq(26, 0);
    int counts= INT32_MAX;
    for(int i=l;i<str.length();i++){
        freq[str[i]-'a']+= 1;
        if(sameFreq(freq)) counts= min(counts, 1+countUtil(str, dp, i+1));
    }
    return dp[l]= counts;
}

void dfs(vector<vector<int>>& graph, vector<bool>& isVisited, vector<vector<int>>& descendents, int src){
    isVisited[src]= true;
    descendents[src].push_back(src);
    vector<bool> taken(graph.size(), false);
    taken[src]= true;
    for(int child: graph[src]){
        if(isVisited[child]) continue;
        dfs(graph, isVisited, descendents, child);

        for(int ele: descendents[child]) if(!taken[ele]) descendents[src].push_back(ele), taken[ele]= true;
    }
}

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges){
    // arrange the nodes with maximum number of children in descending order of their size
    // take the node if it can visit atleast one unvisited nodes       
    vector<vector<int>> graph(n);
    for(int i=0;i<n;i++){
        int u= edges[i][0];
        int v= edges[i][1];
        graph[u].push_back(v);    
    }

    vector<vector<int>> descendents(n);
    vector<bool> isVisited(n, false);
    dfs(graph, isVisited, descendents, 0);

    sort(descendents.begin(), descendents.end(), [](const vector<int>& a, const vector<int>& b){
        return a.size() > b.size();
    });

    vector<bool> taken(n, false);
    vector<int> answer;
    for(int i=0;i<n;i++){
        bool distinct= false;
        for(int ele: descendents[i]){
            if(taken[ele]) continue;
            distinct= true;
            taken[ele]= true;
        }
        if(distinct) answer.push_back(descendents[i][0]);
    }
    return answer;
}

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges){
    vector<vector<int>> redGraph(n);
    for(int i=0;i<redEdges.size();i++){
        int a= redEdges[i][0];
        int b= redEdges[i][1];
        redGraph[a].push_back(b);
    }

    vector<vector<int>> blueGraph(n);
    for(int i=0;i<blueEdges.size();i++){
        int u= blueEdges[i][0];
        int v= blueEdges[i][1];
        blueGraph[u].push_back(v);
    }

    vector<int> altPaths(n, -1);
    altPaths[0]= 0;
    set<tuple<int, char, int>> pq; // <dist, EdgeType, node>

    // intitially insert all the children of 0
    for(int child: redGraph[0]) pq.insert(make_tuple(1, 'R', child)), altPaths[child]= 1;
    for(int child: blueGraph[0]) pq.insert(make_tuple(1, 'B', child)), altPaths[child]= 1;

    while(!pq.empty()){
        auto itr= pq.begin();
        int len= get<0>(*itr);
        char edg= get<1>(*itr);
        int node= get<2>(*itr);
        pq.erase(itr);

        if(edg=='R'){
            for(int child: blueGraph[node]){
                if(altPaths[child]!=-1) continue;
                altPaths[child]= altPaths[node]+1;
                pq.insert(make_tuple(altPaths[child], 'B', child));
            }
        } else{
            for(int child:redGraph[node]){
                if(altPaths[child]!=-1) continue;
                altPaths[child]= altPaths[node]+1;
                pq.insert(make_tuple(altPaths[child], 'R', child));
            }
        }
    }
    return altPaths;
}

long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
    // map every char with the chars in which it can be changed
    vector<vector<long long>> distance(26, vector<long long>(26, LONG_MAX));
    for(int i=0;i<original.size();i++){
        int u= original[i]-'a';
        int v= changed[i]-'a';
        int edgWt= cost[i];
        distance[u][v]= edgWt;
    }
    for(int i=0;i<26;i++) distance[i][i]= 0;

    // apply Floyd-Warshall to calc the min cost required to convert one char into other
    for(int k=0;k<26;k++)
        for(int i=0;i<26;i++)
            for(int j=1;j<26;j++)
                distance[i][j]= min(distance[i][j], distance[i][k]+distance[k][j]);
    
    long long mnCost= 0;
    for(int i=0;i<source.length();i++) mnCost+= distance[source[i]-'a'][target[i]-'a'];
    return mnCost;
}

bool valid(int x, int y, int m, int n){
    return x<m and x>=0 and y<n and y>=0;
}

bool findSafeWalk(vector<vector<int>>& grid, int health){
    // always choose the cell with maxm health
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>> pq; // {health, [x, y]}
    vector<vector<int>> movements= {
        {0, 1}, {1, 0},
        {0, -1}, {-1, 0}
    };

    int m= grid.size();
    int n= grid[0].size();
    vector<vector<bool>> isVisited(m, vector<bool>(n, false));
    grid[0][0]==0 ?  pq.push({health, {0, 0}}) : pq.push({health-1, {0, 0}});
    while(!pq.empty()){
        auto top= pq.top();
        int currHealth= top.first;
        int x= top.second[0];
        int y= top.second[1];
        pq.pop();

        if(isVisited[x][y]) continue;
        if(currHealth<=0) continue;

        isVisited[x][y]= true;
        for(vector<int> movement: movements){
            if(!valid(x+movement[0], y+movement[1], m, n)) continue;
            if(isVisited[x+movement[0]][y+movement[1]]) continue;
            int remHealth= grid[x+movement[0]][y+movement[1]]==0 ? currHealth : currHealth-1;
            pq.push({remHealth, {x+movement[0], y+movement[1]}});
        }

        if(isVisited[m-1][n-1]) break;
    }
    return isVisited[m-1][n-1];
}

vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear){
    // push the node into the queue iff it can be reached before it disappears
    vector<vector<pair<int, int>>> graph(n);
    for(int i=0;i<edges.size();i++){
        int u= edges[i][0];
        int v= edges[i][1];
        int wt= edges[i][2];
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }

    set<pair<int, int>> pq; // {reached time, node}
    vector<int> mnTimes(n, -1);
    pq.insert({0, 0});
    while(!pq.empty()){
        auto itr= pq.begin();
        int time= itr->first;
        int node= itr->second;
        pq.erase(itr);

        mnTimes[node]= time;
        for(pair<int, int> child: graph[node]){
            if(mnTimes[child.first]!=-1) continue;
            int time_to_reach_child= time+child.second;
            if(time_to_reach_child>=disappear[child.first]) continue;
            pq.insert({time_to_reach_child, child.first});
        }
    }
    return mnTimes;
}

void pathUtil(vector<vector<int>>& tree, vector<int>& amount, deque<int> bobPath, int alice, int currProfit, int& maxAliceIncome){
    currProfit= currProfit + (alice==bobPath.back() ? amount[alice]/2 : amount[alice]);
    amount[alice]= amount[bobPath.back()]= 0;
    if(bobPath.back()!=0) bobPath.pop_back();

    if(alice!=0 and tree[alice].size()==1){
        maxAliceIncome= max(maxAliceIncome, currProfit);
    } else{
        for(int next: tree[alice]){
            pathUtil(tree, amount, bobPath, next, currProfit, maxAliceIncome);
        }
    }
}

deque<int> getPath(vector<vector<int>>& tree, vector<bool>& isVisited, int src, int target){
    isVisited[src]= true;
    deque<int> path;
    if(src==target){
        path.push_back(src);
    } else{
        for(int child: tree[src]){
            if(isVisited[child]) continue;
            path= getPath(tree, isVisited, child, target);
            if(path.empty()) continue;
            path.push_front(src);
            break;
        }
    }
    return path;
}

int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount){
    int n= edges.size()+1;
    vector<vector<int>> tree(n);
    for(int i=0;i<edges.size();i++){
        int u= edges[i][0];
        int v= edges[i][1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<bool> isVisited(n, false);
    deque<int> bobPath= getPath(tree, isVisited, 0, bob);

    int maxAliceIncome= INT32_MIN;
    pathUtil(tree, amount, bobPath, 0, 0, maxAliceIncome);
    return maxAliceIncome;
}

bool compareByLength(const string &a, const string &b) {
    return a.size() > b.size(); // Descending order based on length
}  

void replace(string& s, int start, int len){
    while(len>0){
        s[start++]= '*';
        len--;
    }
}

int minExtraChar(string s, vector<string>& dictionary){
    // search for the maximum string in dictionary which is present in s
    sort(dictionary.begin(), dictionary.end(), compareByLength);
    for(int i=0;i<dictionary.size();i++){
        size_t pos= s.find(dictionary[i]);
        if(pos==string::npos) continue;
        replace(s, pos, dictionary[i].length());
    }

    int count= 0;
    for(int i=0;i<s.length();i++)
        if(s[i]!='*')
            count++;
    return count;
}

int main(){

    vector<int> a(3, 1);
    vector<int> b(4, 2);
    b= a;
    for(int ele: b) cout<< ele<< " ";
    set<int> st;
    set<int>::iterator itr = st.end();
    advance(itr, -1);
    
    multiset<pair<int, int>> st;
    

return 0;
}