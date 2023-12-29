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

int closetTarget(vector<string>& words, string target, int startIndex){
    int right_dist= 0;
    int n= words.size();
    int i= startIndex;
    vector<bool> visited(n, false);
    while(words[i]!=target && visited[i]!=true){
        visited[i]= true;
        right_dist++;
        i= (i+1)%n;
    }

    if(visited[i]) return -1; // target not present

    int left_dist= 0;
    i= startIndex;
    while(words[i]!=target){
        left_dist++;
        i= (i-1+n)%n;
    }
    return min(right_dist, left_dist);
}

int main(){



return 0;    
}
