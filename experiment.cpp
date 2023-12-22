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

    int n=5;
    int p= 3, q= -1;
    set<int> allPossibleMarks;
    for(int i=0;i<=n;i++){// correct questions
        for(int j=0;j<=n-i;j++){ // incorrect questions
            int marks= i*p+j*q+(n-i-j)*0; // 0->unattented questions
            allPossibleMarks.insert(marks);
        }
    }
    cout<< "All differrent possible marks:\n";
    for(int ele: allPossibleMarks)
        cout<< ele<<" ";
    cout<< allPossibleMarks.size();


return 0;    
}
