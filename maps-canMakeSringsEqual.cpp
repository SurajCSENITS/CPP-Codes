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

bool ifMakeEqual(string str[], int n)
{
    unordered_map<char, int> frequency;
    for(int i=0;i<n;i++){
        for(int j=0;j<str[i].length();j++){
            if(frequency.find(str[i][j])!=frequency.end()){
                frequency[str[i][j]]+=1;
                continue;
            }
            frequency[str[i][j]]= 1;
        }
    }
    for(auto pair: frequency){
        if(pair.second % n != 0) // checking if multiple of n
            return false;
    }
    return true;
}

int main(){

    // equal no. of each character in each string->then they can be equal
    // no. of each char in the array/no. of strings == integer

    string str[]= {"collegeee","coll","collegge"};
    int n= sizeof(str)/sizeof(str[0]);
    cout<< ifMakeEqual(str, n);

return 0;    
}
