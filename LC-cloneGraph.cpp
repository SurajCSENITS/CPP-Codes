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

// Definition for a Node.
class Node{
public:
    int val;
    vector<Node*> neighbors;

    Node(){
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val){
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors){
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution{
private:
    map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node){
        if(mp.find(node)!=mp.end()) return mp[node];

        Node* cloneNode= new Node(node->val);
        mp[node]= cloneNode;
        for(Node* nei: node->neighbors) cloneNode->neighbors.push_back(cloneGraph(nei));
        return cloneNode;
    }
};

int main(){



return 0;
}