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
    void swap(pair<int, int>* a, pair<int, int>* b){
        pair<int, int> temp= *a;
        *a= *b;
        *b= temp;
    }

    class MaxHeap{ // heap of pairs***
    public:
        vector<pair<int, int>> v;
        int size;
        int capacity;

        MaxHeap(int n){
            size= 0;
            capacity= n+1;
            v.resize(capacity);
        }

        void insertHeap(int value, int idx, Solution& obj){
            // check overflow
            if(size==capacity-1){
                cout<<"Overflow"<<endl;
                return;
            }

            size++;
            v[size].first = value; v[size].second= idx;
            // sort
            int i= size;
            while((i>1) && (v[i].first>v[i/2].first)){
                obj.swap(&v[i], &v[i / 2]);
                i= i/2;
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
                    if(v[2*i].first>v[i].first) obj.swap(&v[i], &v[2*i]);
                    break;
                }
                if(v[i].first>=v[2*i].first && v[i].first>=v[2*i+1].first) break;
                if(v[2*i].first>v[2*i+1].first){
                    obj.swap(&v[i], &v[2*i]);
                    i= 2*i;
                }
                else{ // v[2*i+1]>v[2*i]
                    obj.swap(&v[i], &v[2*i+1]);
                    i= 2*i+1;
                }
            }
        }

        pair<int, int> topHeap(){
            if(size!=0) return v[1];
            return make_pair(-1, -1);
        }
    };

    vector<string> findRelativeRanks(vector<int>& score){
        Solution obj;
        vector<string> answer;
        answer.resize(score.size());
        // insert the scores with their indices in the heap
        MaxHeap mh(score.size());
        for(int i=0;i<score.size();i++) mh.insertHeap(score[i], i, obj);
        int place= 1;
        while(mh.size!=0){
            pair<int, int> top= mh.topHeap();
            if(place==1) answer[top.second]= "Gold Medal";
            else if(place==2) answer[top.second]= "Silver Medal";
            else if(place==3) answer[top.second]= "Bronze Medal";
            else answer[top.second]= to_string(place);
            place++;
            mh.deleteHeap(obj);
        }
        return answer;
    }

};

int main(){

    Solution obj;
    vector<int> score= {10,3,8,9,4};
    vector<string> answer= obj.findRelativeRanks(score);
    for(auto str: answer) cout<< str<< " ";
    

return 0;    
}
