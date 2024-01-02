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


string tictactoe(vector<vector<int>>& moves)
{
    map<int, int> m;
    for(int i=0;i<9;i++) m[i]= -1;

    int i= 0;
    while(i<moves.size()){ // A
        int cellNumber= moves[i][0]*3 + moves[i][1];  // cell number= row×number of columns + column
        m[cellNumber]= 1;
        i= i+2;
    }
    i= 1;
    while(i<moves.size()){ // B
        int cellNumber= moves[i][0]*3 + moves[i][1];  // cell number= row×number of columns + column
        m[cellNumber]= 0;
        i= i+2;
    }
    bool flag= false;

    // check rowwise
    for(int i=0;i<=6;i+=3){
        if(m[i]==m[i+1] && m[i]==m[i+2] && m[i]!=-1){
            flag= true;
            if(m[i]==1) return "A";
            if(m[i]==0) return "B";
        }
    }
    // check columnwise
    for(int i=0;i<3;i++){
        if(m[i]==m[i+3] && m[i]==m[i+6] && m[i]!=-1){
            flag= true;
            if(m[i]==1) return "A";
            if(m[i]==0) return "B";
        }
    }
    // check primary diagonal
    if(m[0]==m[4] && m[0]==m[8] && m[0]!=-1){
        flag= true;
        if(m[0]==1) return "A";
        if(m[0]==0) return "B";
    }
    // check secondary diagonal
    if(m[6]==m[4] && m[6]==m[2] && m[6]!=-1){
        flag= true;
        if(m[6]==1) return "A";
        if(m[6]==0) return "B";
    }

    if(moves.size()<9 && !flag) return "Pending";
    return "Draw";
}


int main(){

    vector<vector<int>> moves= {{0,1},{0,2},{2,2},{1,0},{2,1},{2,0}};
    cout<< tictactoe(moves);

return 0;    
}
