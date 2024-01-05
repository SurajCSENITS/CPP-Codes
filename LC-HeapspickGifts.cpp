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



class Solution {
public:
    void swap(int* a, int* b){
        int temp= *a;
        *a= *b;
        *b= temp;
    }

    class MaxHeap{
    public:
        vector<int> v;
        int size;
        int capacity;

        MaxHeap(int n){
            size= 0;
            capacity= n+1;
            v.resize(capacity);
        }

        void insertHeap(int item, Solution& obj){
            // check overflow
            if(size==capacity-1){
                cout<<"Overflow"<<endl;
                return;
            }

            size++;
            v[size] = item;     
            // sort
            int i= size;
            while ((i>1) && (v[i] > v[i/2])){
                obj.swap(&v[i], &v[i / 2]);
                i = i / 2;
            }
        }

        void deleteHeap(Solution& obj){
            //check underflow
            if(size==0){
                cout<<"Underflow"<<endl;
                return;
            }
            // topmost element is deleted always
            obj.swap(&v[1], &v[size]);
            size--;
            // sort
            int i= 1;
            while(2*i<=size){ // ek chota sa mistake
                if(2*i+1>size){
                    if(v[2*i]>v[i]) obj.swap(&v[i], &v[2*i]);
                    break;
                }
                if(v[i]>=v[2*i] && v[i]>=v[2*i+1]) break;
                if(v[2*i]>v[2*i+1]){
                    obj.swap(&v[i], &v[2*i]);
                    i= 2*i;
                }
                else{ // v[2*i+1]>v[2*i]
                    obj.swap(&v[i], &v[2*i+1]);
                    i= 2*i+1;
                }
            }
        }

        int topHeap(){
            if(size!=0)
                return v[1];
            return -1;
        }
    };

    long long pickGifts(vector<int>& gifts, int k){
        // first create the maxheap for the array gifts
        Solution obj;
        MaxHeap mh(gifts.size());
        for(int ele: gifts) mh.insertHeap(ele, obj);
        for(int ele: mh.v) cout<< ele<<" ";
        cout<< endl;

        while(k>0){ // delete the max element in the heap k times & insert its floor value of sqrt 
            int top= mh.topHeap();
            mh.deleteHeap(obj);
            mh.insertHeap(floor(sqrt(top)), obj);
            for(int ele: mh.v) cout<< ele<<" ";
            cout<< endl;
            k--;
        }
        // calculate the sum of all elements in mh.v
        long long sum= 0;
        for(int i=0;i<gifts.size();i++) sum+= mh.v[i+1];

        return sum;
    }
};

int main(){

    Solution obj;
    vector<int> gifts= {25,64,9,4,100};
    int k;
    cin>> k;
    cout<< obj.pickGifts(gifts, k);
   
return 0;    
}
