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

class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words){
        vector<int> rev_nums; // stores the visited nums in reverse order
        vector<int> output;
        int k= 1;
        for(int i=0;i<words.size();i++){
            if(words[i][0]>=48 && words[i][0]<=57){
                rev_nums.insert(rev_nums.begin(), stoi(words[i]));
                k= 1;
                continue;
            }
            if(k>rev_nums.size()){
                output.push_back(-1);
                continue;
            }
            output.push_back(rev_nums[k-1]);
            k++;
        }
        return output;
    }
};



int main(){

    
    

return 0;    
}
