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
#include <bits/stdc++.h>

int countAnagrams(string str, string ptr){
    int count= 0, k= ptr.length();
    vector<int> freq(26, 0);
    // store the actual frequency of the ptr
    vector<int> originalFreq(26, 0);
    for(char ch: ptr) originalFreq[ch-'a']+=1;

    deque<int> dq;
    // check for the first `k` elements
    int i= 0;
    for(i;i<k;i++) freq[str[i]-'a']+= 1, dq.push_back(i);
    if(freq==originalFreq) count++;

    // slide the window for rest of the elements
    while(i<str.length()){
        freq[str[dq.front()]]-= 1;
        dq.pop_front();

        freq[str[i]-'a']+= 1;
        dq.push_back(i);

        if(freq==originalFreq) count++;
        i+=1;
    }
    return count;
}

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

bool atleast(vector<int>& freq, vector<int>& originalFreq){
    for(int i=0;i<26;i++) if(freq[i]<originalFreq[i]) return false;
    return true;
}

int minWindowSubstring(string s, string t){
    int l= 0, r= 0;
    int mnLen= INT32_MAX;
    string answer= "";

    vector<int> originalFreq(26, 0);
    for(char ch: t) originalFreq[ch-'a']+=1;

    vector<int> freq(26, 0);
    while(r<s.length()){
        freq[s[r++]-'a']+=1;
        if(!atleast(freq, originalFreq)) continue;

        do{
            if(r-l<mnLen)
            {
                answer=s.substr(l,r-l);
                mnLen=r-l;
            }
            freq[s[l++]-'a']-=1;
        } while(atleast(freq, originalFreq));   
    }

    cout<< answer<< " ";
    return mnLen;
}

int main(){

    string s= "timetopractice";
    string t= "toc";
    cout<< minWindowSubstring(s, t)<< endl;

return 0;
}