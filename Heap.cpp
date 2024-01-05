#include <iostream>
using namespace std;
#include <cmath>
#include <string>
#include <time.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <bits/stdc++.h>  

// heap is a complete binary tree

void swap(int* a, int* b){
    int temp= *a;
    *a= *b;
    *b= temp;
}

class MaxHeap
{
public:
    int *arr;
    int size;
    int capacity;

    MaxHeap(int n){
        size= 0;
        capacity= n+1; // as the 0th block is not in use
        arr= (int*)malloc(capacity*sizeof(int));
    }

    void insertHeap(int item){ // insert the element at the last posn and then keep comparing and swaping with its parent
        // check overflow
        if(size==capacity-1){
            cout<<"Overflow"<<endl;
            return;
        }

        size++;
        // arr= (int *)realloc(arr, size * sizeof(int)); // When using realloc(), the old memory block is automatically freed if the reallocation is successful. We don't need to manually call free()not for c++
        arr[size] = item;
        
        // sort
        int i= size;
        while ((i>1) && (arr[i] > arr[i/2])){
            swap(&arr[i], &arr[i / 2]);
            i = i / 2;
        }
    }

    void deleteHeap(){// swap root and last ele, keep comparing the last ele with its maxm child and swap
        //check underflow
        if(size==0){
            cout<<"Underflow"<<endl;
            return;
        }
        // topmost element is deleted always
        swap(&arr[1], &arr[size]);
        size--;
        // sort
        int i= 1;
        bool flag= true;
        while (2*i<=size){
            if (2*i+1 > size){
                if (arr[i] < arr[2 * i])
                    swap(&arr[i], &arr[2 * i]);
                break;
            }
            if((arr[2*i]>arr[2*i+1]) && (arr[2*i]>arr[i])){
                swap(&arr[i], &arr[2 * i]);
                i= 2*i;
                flag= false;
            }
            else if((arr[2*i]<arr[2*i+1]) && (arr[2*i+1]>arr[i])){
                swap(&arr[i], &arr[2*i+1]);
                i= 2*i+1;
                flag= false;
            }
            if(flag)
                break;
            flag= true;          
        }
    }

    int topHeap(){
        if(size!=0)
            return arr[1];
        return -1;
    }

    void displayHeap(){
        for(int i=1;i<=size;i++)
            cout<< arr[i]<<" ";
        cout<< endl;
    }
};

int* heapSort(int array[], int n)
{
    MaxHeap mh(n);
    // first insert every element in heap
    for(int i=0;i<n;i++)
        mh.insertHeap(array[i]);
    // then delete every element from heap
    for(int i=0;i<n;i++)
        mh.deleteHeap();
    // mh.arr is sorted now
    return mh.arr;
}

int* heapify(int arr[], int n){
    int* max_heap= new int[n+1]; // 1th base index
    for(int i=0;i<n;i++) max_heap[i+1]= arr[i];
    
    int i= n; // start from the last index and check whether it has child or not -> find the max child keep swaping*
    while(i>=1){
        if(2*i>n){
            i--;
            continue;
        }
        if(2*i+1>n){
            if(max_heap[2*i]>max_heap[i]) swap(&max_heap[i], &max_heap[2*i]);
            i--;
            continue;
        }
        int k= i;
        while(2*k<=n){
            if(max_heap[k]>max_heap[2*k] && max_heap[k]>max_heap[2*k+1]) break;
            if(max_heap[2*k]>max_heap[2*k+1]){
                swap(&max_heap[k], &max_heap[2*k]);
                k= 2*k;
            }
            else if(max_heap[2*k+1]>max_heap[2*k]){
                swap(&max_heap[k], &max_heap[2*k+1]);
                k= 2*k+1;
            }
        }
        i--;
    }

    return max_heap;    
}

int main(){

    // MaxHeap mh(20);
    // mh.insertHeap(15);
    // mh.insertHeap(20);
    // mh.insertHeap(11);
    // mh.insertHeap(18);
    // mh.insertHeap(10);
    // mh.insertHeap(8);
    // mh.insertHeap(16);
    // mh.insertHeap(50);
    // mh.displayHeap();
    // mh.deleteHeap();
    // mh.displayHeap();
    // cout<< mh.topHeap();

    // heapSort
    int array[]={20,18,16,15,10,8,11};
    int n= sizeof(array)/sizeof(array[0]);
    heapSort(array, n);

    // heapify
    int arr[]= {6,5,7,8,10};
    int* max_heap= heapify(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i=1;i<sizeof(arr)/sizeof(arr[0])+1;i++) cout<< max_heap[i]<<" ";
        
return 0;
}
