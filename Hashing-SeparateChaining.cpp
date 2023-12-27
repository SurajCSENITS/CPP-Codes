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
#include <bits/stdc++.h>  

class Hashing
{
private:
    vector<vector<int>> hashtable;
    int buckets;
public:
    Hashing(int n){
        buckets= n;
        hashtable.resize(buckets);
    }
    int hashvalue(int val){
        return (val%buckets); // hash function
    }
    void addVal(int val){
        int idx= hashvalue(val);
        hashtable[idx].push_back(val);
    }
    vector<int>::iterator searchVal(int val){
        int idx= hashvalue(val);
        return find(hashtable[idx].begin(), hashtable[idx].end(), val); // vetcor's find() syntax is diff from that of sets
    }
    void deleteVal(int val){
        int idx= hashvalue(val);
        if(searchVal(val)!=hashtable[idx].end()){
            hashtable[idx].erase(searchVal(val));
            cout<< "Element deleted from idx "<<idx<<endl;
        }
        else{
            cout<< "Element not present";
        }
        
    }
};

int main(){

    // Implement Hash Table with closed adderessing/separate chaining
    Hashing h(10);
    h.addVal(5);
    h.addVal(3);
    h.addVal(9);
    h.deleteVal(3);
    h.deleteVal(3);

return 0;    
}
