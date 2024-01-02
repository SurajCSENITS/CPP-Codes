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

bool isPrime(int n){
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0) return false;
    return true;
}

int main(){

   // how to check for a prime number
   // prime numbers>=2
   // Check if 'n' is divisible by any integer from 2 up to √n (square root of 'n').
   // If 'n' is divisible by any of these integers, it's not a prime number.
   // If 'n' is not divisible by any integer in the range, it's a prime number.
    
    int n;
    cin>> n;
    cout<< isPrime(n);

return 0;    
}
