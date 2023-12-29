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

void reduceArray(int array[], int n, int prevMin= INT_MIN, int count= 0)
{
    if(count==n) return;

    int min= INT32_MAX;
    int minIdx;
    for(int i=0;i<n;i++){
        if(min>array[i] && array[i]>prevMin){
            min= array[i];
            minIdx= i;
        }
    }
    // min is storing the min element and minIdx is storing the min ele Idx;
    array[minIdx]= count++;
    reduceArray(array, n, min, count);
    
}

int main(){

    int array[]= {10,16,7,14,5,3,12,9};
    updateArray(array, 8);
    for(int i=0;i<8;i++)
        cout<< array[i]<<" ";

return 0;    
}
