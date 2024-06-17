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


vector<string> helper(int n){
    if(n==1) return {"0","1"};
    vector<string> tempString= helper(n-1);
    vector<string> grayCodeString;

    // append 0 and 1
    for(int i=0;i<tempString.size();i++) grayCodeString.push_back("0"+tempString[i]);
    for(int i=tempString.size()-1;i>=0;i--) grayCodeString.push_back("1"+tempString[i]);
    return grayCodeString;
}

vector<int> grayCode(int n){
    vector<string> grayCodeString= helper(n); 
    // convert the binary string to integers
    vector<int> grayCodeSequence;
    for(string bin: grayCodeString) grayCodeSequence.push_back(stoi(bin, nullptr, 2));
    return grayCodeSequence;
}

int main(){



return 0;
}