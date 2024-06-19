#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <bits/stdc++.h>

class Node{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val= val;
        next= prev= nullptr;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() { head= tail= nullptr; }

    void insertAtHead(int val){
        Node* new_node= new Node(val);
        if(head){
            head= tail= new_node;
            return;
        }

        new_node->next= head;
        head->prev= new_node;
        head= new_node;
    }

    void insertAtTail(int val){
        Node* new_node= new Node(val);
        if(tail){
            head= tail= new_node;
            return;
        }

        tail->next= new_node;
        new_node->prev= tail;
        tail= new_node;
    }

    void insertAtKth(int val, int k){
        if(k==1){
            insertAtHead(val);
            return;
        }

        Node* ptr= head;
        while(k>1) ptr= ptr->next, k--;
        Node* new_node= new Node(val);
        // make the new connections
        ptr->prev->next= new_node;
        new_node->prev= ptr->prev;
        new_node->next= ptr;
        ptr->prev= new_node;
    }

    void deleteAtHead(){
        Node* temp= head;
        if(head->next==nullptr){
            head= tail= nullptr;
            free(temp);
            return;
        }

        head= head->next;
        head->prev= nullptr;
        free(temp);
    }

    void deleteAtTail(){
        Node* temp= tail;
        if(tail->prev==nullptr){
            head= tail= nullptr;
            free(temp);
            return;
        }

        tail= tail->prev;
        tail->next= nullptr;
        free(temp);
    }

    void deleteAtKth(int k){
        if(k==1){
            deleteAtHead();
            return;
        }

        Node* ptr= head;
        while(k>1) ptr= ptr->next, k--;
        if(ptr==tail){
            deleteAtTail();
            return;
        }

        ptr->prev->next= ptr->next;
        ptr->next->prev= ptr->prev;
        free(ptr);
    }

    void reverseList(){
        Node* curr= head;
        while(curr){
            Node* next= curr->next;
            curr->next= curr->prev;
            curr->prev= next;
            curr= next;
        }
        swap(head, tail);
    }

    bool isPalindrome(){
        Node* head_ptr= head;
        Node* tail_ptr= tail;
        bool palindrome= true;
        while(head_ptr->prev != tail_ptr){
            if(head_ptr->val != tail_ptr->val){
                palindrome= false;
                break;
            }
            head_ptr= head_ptr->next;
            tail_ptr= tail_ptr->prev;
        }
        return palindrome;
    }

    void deleteNodeWithSameNeighbours(){
        Node* ptr= tail->prev;
        while(ptr!=head){
            Node* prev= ptr->prev;
            if(ptr->next->val == ptr->prev->val){
                ptr->prev->next= ptr->next;
                ptr->next->prev= ptr->prev;
                free(ptr);
            }
            ptr= prev;
        }
    }

    vector<int> criticalPoints(){
        vector<int> dist(2);
        dist[0]= INT32_MAX, dist[1]= INT32_MIN;
        int pos= 1, first= -1;

        Node* ptr= head->next;
        while(ptr!=tail){
            // check if critical point
            if((ptr->val<ptr->next->val and ptr->val<ptr->prev->val) or (ptr->val>ptr->next->val and ptr->val>ptr->prev->val)){
                if(first==-1) first= pos;
                else{
                    dist[0]= min(dist[0], pos-first);
                    dist[1]= pos-first;
                }
            }
            ptr= ptr->next;
            pos+= 1;
        }
        if(dist[0]==INT32_MAX) return {-1, -1};
        return dist;
    }

    vector<int> targetSum(int target){ // sorted DLL
        Node* head_ptr= head;
        Node* tail_ptr= tail;
        vector<int> answer(2, -1);

        while(head_ptr!=tail_ptr){
            if(head_ptr->val+tail_ptr->val == target){
                answer[0]= head_ptr->val;
                answer[1]= tail_ptr->val;
                break;
            }

            if(head_ptr->val+tail_ptr->val < target) head_ptr= head_ptr->next;
            else tail_ptr= tail_ptr->prev;
        }
        return answer;
    }   
};


int main(){



return 0;
}