#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>

class Node{
public:
    int val;
    Node* next;

    Node(int item){
        val= item;
        next= NULL;
    }
};

class Graph{
private:
    Node** list;
    int v; 
    int e;
public:
    Graph(int vert, int edge){
        v= vert;
        e= edge;
        list = new Node*[v];  // Allocate memory for the list

        for(int i=0;i<v;i++)
            list[i]= new Node(i);
    }
    void createGraph()
    {
        cout<<"Enter adjacent vertices(a pair should be entered only once, irrespective of its order)"<<endl;
        for(int i=0;i<e;i++){
            int a, b;
            cin>>a>>b;
            // a->next= b b->next= a
            Node* temp= list[a];
            while(temp->next!=NULL)
                temp= temp->next;
            Node* new_node= new Node(b);
            temp->next= new_node;

            temp= list[b];
            while(temp->next!=NULL)
                temp= temp->next;
            new_node= new Node(a);
            temp->next= new_node;
        }
    }
    void display(){
        for(int i=0;i<v;i++){
            Node* temp= list[i];
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp= temp->next;
            }
            cout<< endl;
        }
    }
};

int main(){

    int v, e;
    cin>>v;
    cin>>e;
    Graph gph(v, e);
    gph.createGraph();
    gph.display();

return 0;    
}