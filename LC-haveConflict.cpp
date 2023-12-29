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

bool haveConflict(vector<string>& event1, vector<string>& event2){
    // claculate time wrt 00:00 in terms of minutes
    int st1= stoi(event1[0].substr(0, 2))*60 + stoi(event1[0].substr(3, 2));
    int st2= stoi(event2[0].substr(0, 2))*60 + stoi(event2[0].substr(3, 2));
    int et1= stoi(event1[1].substr(0, 2))*60 + stoi(event1[1].substr(3, 2));
    int et2= stoi(event2[1].substr(0, 2))*60 + stoi(event2[1].substr(3, 2));

    // check condition
    if((st1<=st2 && st2<=et1) || (st1<=et2 && et2<=et1)) return true;
    if((st2<=st1 && st1<=et2) || (st2<=et1 && et1<=et2)) return true;
    return false;

}


int main(){

     

return 0;    
}
