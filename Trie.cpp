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

class Node{
public:
    vector<Node*> children;
    bool eow; // End Of Word

    Node(){
        children.resize(26, nullptr);
        eow= false;
    }
};

class Trie{ // Apna College: https://youtu.be/m9zawMC6QAI
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

bool searchInTrie(Node* root, string key){ // O(L)
    bool isPresent= true;
    for(int i=0;i<key.length();i++){
        int idx= key[i]-'a';
        if(root->children[idx]==nullptr){
            isPresent= false;
            break;
        }
        root= root->children[idx];
    }
    // check for end of word
    return isPresent ? isPresent= root->eow : isPresent;
}

bool wordBreakUtil(string& key, Node* root, int start= 0){
    if(start==key.length()) return true;

    string temp= "";
    for(int i=start;i<key.length();i++){
        temp+= key[i];
        if(searchInTrie(root, temp)){
            bool rem= wordBreakUtil(key, root, i+1);
            if(rem) return true;
        }
    }
    return false;
}

bool wordBreak(string& key, vector<string>& dictionary){
    // create a TRIE for the dictionary
    Trie trie;
    for(int i=0;i<dictionary.size();i++) insertInTrie(trie.root, dictionary[i]);
    return wordBreakUtil(key, trie.root);
}

bool startsWith(string prefix, vector<string>& dictionary){
    // create a TRIE for the dictionary
    Trie trie;
    for(int i=0;i<dictionary.size();i++) insertInTrie(trie.root, dictionary[i]);

    Node* root= trie.root;
    for(int i=0;i<prefix.length();i++){
        int idx= prefix[i]-'a';
        if(root->children[idx]==nullptr) return false;
        root= root->children[idx];
    }
    return true;
}

int countNodes(Node* root){
    int count= 1;
    for(Node* child: root->children){
        if(child==nullptr) continue;
        count+= countNodes(child);
    }
    return count;
}

int uniqueSubstrings(string str){
    // Create a TRIE
    // Insert all the suffixes of str into the TRIE
    Trie trie;
    Node* root= trie.root;
    while(!str.empty()){
        insertInTrie(root, str);
        str.erase(str.begin());
    }
    // total no. of nodes equals the number of unique substrings/unique prefixes of all suffixes
    return countNodes(root);
}

void longestWordUtil(Node* root, string& ans, string curr= ""){
    if(curr.length()>ans.length()) ans= curr;

    // iterate through every child of root in alphabetical(default) order
    for(int i=0;i<root->children.size();i++){
        Node* curr_child= root->children[i];
        if(curr_child==nullptr or curr_child->eow==false) continue;
        curr.push_back(i+'a');
        longestWordUtil(curr_child, ans, curr);
        curr.pop_back(); // backtrack
    }
}

string longestWord(vector<string>& dictionary){
    // create a TRIE for the words in dictionary
    Trie trie;
    Node* root= trie.root;
    for(int i=0;i<dictionary.size();i++) insertInTrie(root, dictionary[i]);

    string ans= "";
    longestWordUtil(root, ans);
    return ans;
}

int main(){

    Trie trie;
    vector<string> words= {"the","a","there","their","any"};
    for(int i=0;i<words.size();i++) insertInTrie(trie.root, words[i]);

    cout<< searchInTrie(trie.root, "their")<< endl;
    cout<< searchInTrie(trie.root, "thor")<< endl;
    cout<< searchInTrie(trie.root, "an")<< endl;

    vector<string> dictionary= {"i","like","sam","samsung","mobile","ice"};
    string key= "ilikesamsung";
    cout<< wordBreak(key, dictionary)<< endl;
    
    dictionary.clear();
    dictionary= {"apple","app","mango","man","woman"};
    string prefix1= "app", prefix2= "moon";
    cout<< startsWith(prefix1, dictionary)<< " "<< startsWith(prefix2, dictionary)<< endl;

    cout<< uniqueSubstrings("ababa")<< endl;

    dictionary.clear();
    dictionary= {"a","banana","app","appl","ap","apply","apple"};
    cout<< longestWord(dictionary)<< endl;

return 0;    
}
