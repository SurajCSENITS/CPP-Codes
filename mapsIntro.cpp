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
#include <bits/stdc++.h>  


int main(){

    map<string, int> directory;// string->keyDatatype int->valueDatatype

    //insertion in a map
    directory["naman"]= 3876; // directory[key]=value
    directory["animesh"]= 74102;
    directory["ritu"]= 26578;
    directory= {{"suraj", 5332}};
    //Note
    directory.insert(make_pair("ritu", 34443));// if the pair is not present then it will insert it otherwise it will do nothing

    //iteration in a map
    for(auto element:directory){
        cout<<"Name: "<<element.first<<endl;
        cout<<"Ph. No: "<<element.second<<endl;
    }
    map<string, int>:: iterator itr;
    for(itr=directory.begin();itr!=directory.end();itr++)
        cout<< itr->first<<"-"<<itr->second<<endl;

    //updation
    directory["ritu"]= 79650;
    
    // Repeatetive elements sum
    // frequency logic in maps
    vector<int> v= {1,1,2,1,3,3,3};
    map<int, int> frequency;
    for(int ele: v){
        if(frequency.count(ele)!=0){
            frequency[ele]+=1;
            continue;
        }
        frequency[ele]= 1;     
    }
    int sum= 0;
    for(auto pair: frequency){
        if(pair.second>1)
            sum+=pair.first;
    } cout<<sum;
    

return 0;    
}
