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

int divisorSubstrings(int num, int k){
    string str= to_string(num);
    string substr= "";
    int beauty= 0, temp;
    // insert first k elements
    int i= 0;
    for(i;i<k;i++) substr.push_back(str[i]);
    temp= stoi(substr);
    if(temp!=0 && num%temp==0) beauty++;
    // slide window for rest of the elements
    for(i;i<str.size();i++){
        substr.erase(substr.begin());
        substr.push_back(str[i]);
        temp= stoi(substr);
        if(temp!=0 && num%temp==0) beauty++;
    }
    return beauty;
}

int main(){

    int num, k;
    cin>> num>> k;
    cout<< divisorSubstrings(num, k);

return 0;    
}
