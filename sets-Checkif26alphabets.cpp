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
#include <bits/stdc++.h>  

bool checkIf26alphabets(string str){
    if(str.length()<26) return false;
    set<char> charSet;
    
    for(int i=0;i<str.length();i++){
        if(str[i]<=97 && str[i]>=65)
            str[i]+=32;// converting all chars into smaller case
        charSet.insert(str[i]);
    }
    // transform(str.begin(), str.end(), str.begin(), ::tolower); // each char lega usko lower case me convert karega and str.brgin() se dalte jayga
    if(charSet.size()==26)
        return true;
    else
        return false;
}

int main(){

    string str= "subdermatoglyphic";
    cout<< checkIf26alphabets(str);
    


return 0;    
}