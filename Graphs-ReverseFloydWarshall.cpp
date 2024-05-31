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


vector<int> getSumBeforeNodeDeletion(vector<vector<int>>& distance, vector<int> delOrder){
    int n= delOrder.size();
    vector<int> answer;
    reverse(delOrder.begin(), delOrder.end());
    for(int k=0;k<n;k++){
        int added_node= delOrder[k];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                distance[i][j]= min(distance[i][j], distance[i][added_node]+distance[added_node][j]);
            }
        }
        // calculate the all pair shortest path sum of every added nodes
        int sum= 0;
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                sum+= distance[delOrder[i]][delOrder[j]];
            }
        }
        answer.push_back(sum);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main(){



return 0;    
}