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

void permutations(string str, string ans= ""){ // College Wallah -> Backtracking part 1
    if(str=="") cout<< ans<< endl;

    for(int i=0;i<str.length();i++){
        string copy= str;
        copy.erase(i, 1);
        permutations(copy, ans+str[i]);
    }   
}

int main(){

    string str= "abc";
    permutations(str);

    
return 0;    
}
