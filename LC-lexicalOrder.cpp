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

class Node{
public:
    vector<Node*> children;
    Node() : children(10, nullptr) {}
};

class Trie{
public:
    Node* root;
    Trie() : root(new Node()) {}
};

void insertInTrie(Node* root, string number){
    for(int i=0;i<number.length();i++){
        int idx= number[i]-'0';
        if(root->children[idx] == nullptr) root->children[idx]= new Node();
        root= root->children[idx];
    }
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

int main(){



return 0;
}