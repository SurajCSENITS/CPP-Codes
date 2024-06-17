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

    Node(int val){
        this->val= val;
        next= nullptr;
    }
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList(){ head= nullptr; }

    void insertAtHead(int val){
        Node* new_node= new Node(val);
        new_node->next= head;
        head= new_node;
    }

    void insertAtKth(int val, int k){
        if(k==0){
            insertAtHead(val);
            return;
        }

        Node* k_b4= head;
        while(k>1) k_b4= k_b4->next, k--;
        Node* new_node= new Node(val);
        new_node->next= k_b4->next;
        k_b4->next= new_node;
    }

    void updateAtKth(int val, int k){
        Node* temp= head;
        while(k>0) temp= temp->next, k--;
        temp->val= val;
    }

    void display(){
        Node* temp= head;
        while(temp!=nullptr) cout<< temp->val<< "->", temp= temp->next;
        cout<< "NULL";
    }

    void deleteAtHead(){
        Node* old_head= head;
        head= head->next;
        free(old_head);
    }

    void deleteAtKth(int k){
        if(k==0){
            deleteAtHead();
            return;
        }

        Node* k_b4= head;
        while(k>1) k_b4= k_b4->next, k--;
        Node* kthNode= k_b4->next;
        k_b4->next= kthNode->next;
        free(kthNode); 
    }

    void deleteAlternate(){
        Node* curr= head;
        while(curr!=nullptr and curr->next!=nullptr){
            Node* temp= curr->next;
            curr->next= temp->next;
            free(temp);
            curr= curr->next;
        }
    }

    void deleteDuplicatesInSorted(){
        Node* curr= head;
        while(curr->next!=nullptr){
            if(curr->val!=curr->next->val){
                curr= curr->next;
                continue;
            }
            // delete curr->next
            Node* to_del= curr->next;
            curr->next= to_del->next;
            free(to_del);
        }
    }
};

int main(){


return 0;
}