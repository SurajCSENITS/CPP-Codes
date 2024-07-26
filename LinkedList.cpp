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
public:
    Node* head;

    LinkedList(){ head= nullptr; }

    void insertAtHead(int val){
        Node* new_node= new Node(val);
        new_node->next= head;
        head= new_node;
    }

    void insertAtTail(int val){
        Node* new_node= new Node(val);
        if(head==nullptr){
            head= new_node;
            return;
        }

        Node* tail= head;
        while(tail->next) tail= tail->next;
        tail->next= new_node;
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
        cout<< "NULL"<< endl;
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

void printInReverse(Node* head){
    if(head==nullptr) return;
    printInReverse(head->next);
    cout<< head->val<< " ";
}

Node* revereseList(Node* head){
    Node* curr= head;
    Node* prev= nullptr;
    while(curr!=nullptr){
        Node* next= curr->next;
        curr->next= prev;
        prev= curr, curr= next;
    }
    return prev; // new head of reveresed LL
}

Node* reverseListRecursive(Node* head){
    if(head==nullptr or head->next==nullptr) return head;
    Node* new_head= reverseListRecursive(head->next);
    head->next->next= head;
    head->next= nullptr;
    return new_head;
}

Node* reversePerKNodes(Node* head, int k){
    if(head==nullptr) return head;

    Node* curr= head;
    Node* prev= nullptr;
    for(int i=0;curr!=nullptr and i<k;i++){
        // reverse first k nodes reccursively
        Node* next= curr->next;
        curr->next= prev;
        prev= curr, curr= next;
    }
    // get answer for the remaining LL
    Node* remLL= reversePerKNodes(curr, k);
    head->next= remLL;
    return prev; // new_head
} 

int getLength(Node* head){
    int len= 0;
    while(head!=nullptr) head= head->next, len++;
    return len;
}

void advance(Node* head, int k){ while(k) head= head->next, k--; }

Node* getIntersection(Node* head1, Node* head2){
    //step1: calculate the length of the two lists
    int l1= getLength(head1);
    int l2= getLength(head2);

    //step2: advance the ptr of longer list
    if(l1>l2) advance(head1, l2-l1);
    else if(l2<l1) advance(head2, l1-l2);
    
    //step3: get the common node
    Node* intersection= nullptr;
    while(head1!=nullptr){
        if(head1==head2){ // pointing to the same node
            intersection= head1;
            break;
        }
        head1= head1->next;
        head2= head2->next;
    }
    return intersection;
}

void deleteKthFromEnd(Node* head, int k){
    // k=1 means delete the last node
    // single traversal method
    Node* l= head;
    Node* r= head;
    while(k) r= r->next, k--;
    if(r==nullptr){
        head= head->next;
        free(l);
        return;
    }

    while(r->next!=nullptr) l= l->next, r= r->next;
    // l is now pointing to k+1th node from end
    Node* to_del= l->next;
    l->next= to_del->next;
    free(to_del);
}

Node* mergeSortedList(Node* head1, Node* head2){
    Node* dummy_head= new Node(-1);
    Node* dummy_tail= dummy_head;
    
    while(head1 and head2){
        if(head1->val <= head2->val){
            dummy_tail->next= head1;
            dummy_tail= dummy_tail->next;
            head1= head1->next;
        }else {
            dummy_tail->next= head2;
            dummy_tail= dummy_tail->next;
            head2= head2->next;
        }
    }

    while(head1) dummy_tail->next= head1, dummy_tail= dummy_tail->next, head1= head1->next;
    while(head2) dummy_tail->next= head2, dummy_tail= dummy_tail->next, head2= head2->next;
    return dummy_head->next; // actual head of the merged LL
}

Node* mergeKSortedList(vector<Node*>& heads){
    while(heads.size()>1){
        Node* ll1= heads.back();
        heads.pop_back();
        Node* ll2= heads.back();
        heads.pop_back();
        Node* merged_ll= mergeSortedList(ll1, ll2);
        heads.insert(heads.begin(), merged_ll);
    }
    return heads.back();
}

Node* getMiddleNode(Node* head){
    Node* slow= head;
    Node* fast= head;
    while(fast!=nullptr and fast->next!=nullptr) fast= fast->next->next, slow= slow->next;
    return slow;
}

bool isCyclic(Node* head){
    if(head==nullptr or head->next==nullptr or head->next->next==nullptr) return;

    Node* slow= head;
    Node* fast= head;
    bool isCyclic= false;
    do{
        fast= fast->next->next;
        slow= slow->next;
    } while(fast!=nullptr and fast->next!=nullptr and slow!=fast);

    if(slow==fast) isCyclic= true;
    return isCyclic;
}

void removeCycle(Node* head){
    if(head==nullptr or head->next==nullptr or head->next->next==nullptr) return;

    Node* slow= head;
    Node* fast= head;
    do{
        fast= fast->next->next;
        slow= slow->next;
    } while(fast!=nullptr and fast->next!=nullptr and slow!=fast);

    if(fast==nullptr or fast->next==nullptr) return; // No cycle present
    fast= head; // Now keep advancing slow and fast pointers by 1 step
    while(slow->next!=fast->next) slow= slow->next, fast= fast->next;
    slow->next= nullptr; // slow pointing to the last node 
}

bool isPlaindrome(Node* head){
    Node* middleNode= getMiddleNode(head);
    Node* rev_head= revereseList(middleNode);
    // check if two halves are equal or not
    bool palindrome= true;
    while(rev_head){
        if(head->val!=rev_head->val){
            palindrome= false;
            break;
        }
        head= head->next;
        rev_head= rev_head->next;
    }
    return palindrome;
}

void rightRotate(Node* &head, int k){
    // find the tail node
    Node* tail= head;
    int n= 1;
    while(tail->next!=nullptr) tail= tail->next, n++;
    k= k%n;
    if(k==0) return;
    // traverese by n-k-1 steps
    Node* ptr= head;
    for(int i=0;i<n-k-1;i++) ptr= ptr->next;
    Node* new_head= ptr->next;
    // connect the new links
    tail->next= head;
    ptr->next= nullptr;
    head= new_head;
}

void groupOddThenEvenIndices(Node* &head){
    Node* odd_head= head;
    Node* even_head= head->next;
    Node* odd_tail= head;
    Node* even_tail= head->next;

    while(even_tail and even_tail->next) odd_tail= odd_tail->next= odd_tail->next->next, even_tail= even_tail->next= even_tail->next->next;
    odd_tail->next= even_head;
    head= odd_head;
}

void reorderList(Node* head){
    Node* middleNode= getMiddleNode(head);
    Node* r= revereseList(middleNode);
    Node* l= head;
    while(r->next!=nullptr){
        Node* l_next= l->next;
        Node* r_next= r->next;
        l->next= r, r->next= l_next;
        l= l_next, r= r_next;
    }
}

int main(){

    // LinkedList ll;
    // ll.insertAtHead(6);
    // ll.insertAtHead(5);
    // ll.insertAtHead(4);
    // ll.insertAtHead(3);
    // ll.insertAtHead(2);
    // ll.insertAtHead(1);
    // ll.display();

    // ll.insertAtKth(99, 1);
    // ll.updateAtKth(99, 1);
    // ll.deleteAtKth(1);
    // ll.deleteAlternate();
    // ll.deleteDuplicatesInSorted();
    // printInReverse(ll.head);
    // ll.head= reverseListRecursive(ll.head);
    // ll.head= reversePerKNodes(ll.head, 4);
    // ll.display();

    // LinkedList ll1;
    // ll1.insertAtTail(1);
    // ll1.insertAtTail(7);
    // ll1.insertAtTail(8);
    // ll1.display();

    // LinkedList ll2;
    // ll2.insertAtTail(2);
    // ll2.insertAtTail(4);
    // ll2.insertAtTail(5);
    // ll2.display();

    // LinkedList ll3;
    // ll3.insertAtTail(3);
    // ll3.insertAtTail(6);
    // ll3.display();

    // LinkedList ll_merged;
    // ll_merged.head= mergeSortedList(ll1.head, ll2.head);
    // ll_merged.display();

    // vector<Node*> heads= {ll1.head, ll2.head, ll3.head};
    // LinkedList ll_merged;
    // ll_merged.head= mergeKSortedList(heads);
    // ll_merged.display();

    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();

    // Node* middleNode= getMiddleNode(ll.head);
    // cout<< middleNode->val<< endl; 

    // ll.head->next->next->next->next= ll.head->next;
    // cout<< isCyclic(ll.head)<< endl;
    // removeCycle(ll.head);
    // cout<< isCyclic(ll.head)<< endl;
    // ll.display();

    // cout<< isPlaindrome(ll.head);

    // rightRotate(ll.head, 3);
    // ll.display();

    // groupOddThenEvenIndices(ll.head);
    // ll.display();

    reorderList(ll.head);
    ll.display();

return 0;
}