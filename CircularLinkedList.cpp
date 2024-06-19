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

class CircularLinkedList{
public:
    Node* head;

    CircularLinkedList(){ head= nullptr; }

    void insertAthead(int val){
        Node* new_node= new Node(val);
        if(head){
            head= new_node;
            head->next= head;
            return;
        }
        // get tail node
        Node* tail= head;
        while(tail->next!=head) tail= tail->next;
        // make the new links
        tail->next= new_node;
        new_node->next= head;
        head= new_node;
    }

    void insertAtTail(int val){
        Node* tail= head;
        while(tail->next!=head) tail= tail->next;
        Node* new_node= new Node(val);
        // make new links       
        tail->next= new_node;
        new_node->next= head;
    }

    void display(){
        Node* ptr= head;
        do{
            cout<< ptr->val<< " ";
            ptr= ptr->next;
        } while(ptr!=head);
    }

    void deleteAtHead(){
        Node* tail= head;
        while(tail->next!=head) tail= tail->next;
        tail->next= head->next;
        Node* to_del= head;
        head= head->next;
        free(to_del);
    }

    void deleteAtTail(){
        Node* ptr= head;
        while(ptr->next->next!=head) ptr= ptr->next;
        Node* to_del= ptr->next;
        ptr->next= head;
        free(to_del);
    }
};




int main(){



return 0;
}