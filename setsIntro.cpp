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

int main(){

    set<int> set1;
    // set1={1,1,23,3,3,4};
    // set<int, greater<int>> set1; // dec order

    set1.insert(3);
    set1.insert(2);
    set1.insert(1);
    set1.insert(4);
    set1.insert(5);

    cout<< set1.size()<<endl;

    set1.insert(3);
    cout<< set1.size()<<endl; // size remains same [1,2,3,4,5]

    // iteration in a set
    set<int>::iterator itr;
    for(itr=set1.begin();itr!=set1.end();itr++)
        cout<< *itr<<" ";
    cout<<endl;

    for(int value:set1)
        cout<< value<< " ";
    cout<< endl;

    // deletion
    // set1.erase(4); // deletes value 4
    // auto itr= set1.begin();
    // advance(itr, 3);
    // set1.erase(itr); // deletes 4
    // set1.insert(4);
    auto start_itr= set1.begin();
    start_itr++; // 2
    auto end_itr= set1.begin();
    advance(end_itr, 3); // 4
    set1.erase(start_itr, end_itr); //[1,4,5]

    if(set1.find(4)!=set1.end())
        cout<<"value is present"<<endl;
    else
        cout<<"value is not present"<<endl;

    set<string> names= {"Suraj", "Abhishek", "Suraj", "Prateek", "Ankit", "Arif"};
    for(string it: names)
        cout<< it<<" "; // lexicographical order

    // unordered set
    unordered_set<int> us1;
    us1.insert(1);
    us1.insert(3);
    us1.insert(2);
    us1.insert(3);
    
    // multiset
    multiset<int> ms;
    ms.insert(2);
    ms.insert(2);
    ms.insert(1);
    ms.insert(3);

return 0;    
}
