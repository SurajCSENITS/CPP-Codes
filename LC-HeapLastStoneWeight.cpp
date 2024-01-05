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


class Solution{
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
            if(size!=0) return v[1];               
            return -1;
        }
    };

    int lastStoneWeight(vector<int>& stones){
        Solution obj;
        MaxHeap mh(stones.size());
        // insert elements to heap
        for(int ele: stones) mh.insertHeap(ele, obj);
        while(mh.size>1){
            int y= mh.topHeap(); mh.deleteHeap(obj);// larger one
            int x= mh.topHeap(); mh.deleteHeap(obj);// 2nd larger one

            int wtAfterCollsion= y-x;
            if(wtAfterCollsion==0) continue;
            mh.insertHeap(wtAfterCollsion, obj);
        }
        if(mh.size==0) return 0;
        return mh.v[1];
    }
};

int main(){

    Solution obj;
    vector<int> stones= {2,7,4,1,8,1};
    cout<< obj.lastStoneWeight(stones);

return 0;    
}
