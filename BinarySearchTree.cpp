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
#include <bits/stdc++.h>  


class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int item){
        data= item;
        left= nullptr;
        right= nullptr;
    }
};

class BST
{
public:
    Node* root;

    BST(){ root= nullptr; }
        
    void insert(int item){
        Node* new_node= new Node(item);

        if(root==nullptr){
            root= new_node;
            return;
        }

        Node* ptr= root;
        while(true){
            if(item == ptr->data) return; // no duplicates
            else if(item < ptr->data){
                if(ptr->left == nullptr){
                    ptr->left= new_node;
                    return;
                }
                else ptr= ptr->left;
            }
            else{
                if(ptr->right==nullptr){
                    ptr->right= new_node;
                    return;
                }
                else ptr= ptr->right;
            }
        }
    }

    Node* search(int key, Node* ptr){
        if(ptr==nullptr || ptr->data == key) return ptr;
        if(key < ptr->data) return search(key, ptr->left); // jump on left subtree
        else return search(key, ptr->right); // jump on right subtree
    }

    Node* remove(int key, Node* root){ // returning updated root node
        if(root==nullptr) return nullptr; // key does not exist

        if(key < root->data) root->left= remove(key, root->left);
        else if(key > root->data) root->right= remove(key, root->right);

        // if key == root->data      
        else
        {
            if(root->left == nullptr and root->right == nullptr){// case 1 : target root has no child
                return nullptr; // delete node, return null to parent
            }
            else if(root->left == nullptr || root->right == nullptr){// case 2 : target root has one child
                if(root->left != nullptr) return root->left; // delete node and replace with its child
                if(root->right != nullptr) return root->right; // delete node and replace with its child
            }
            // case 3 : target root has both childs -> replace node with its inorder successer & delete
            else{
                Node* temp= root->right; 
                while(temp->left != nullptr) temp= temp->left; // right subtree ka leftmost node
                root->data= temp->data;
                root->right= remove(temp->data, root->right);//delete the inorder successer -> either fall in case 1 or 2
            }
        }
        return root;
    }
};

void inorder(Node* root)
{ // inorder traversal of BST is sorted
    if(root== NULL)
        return;
    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}

vector<int> printInRange(int x, int y, Node* root){
    vector<int> res;
    if(root==nullptr) return res;

    if(root->data >= x and root->data <= y){
        res.push_back(root->data);
        vector<int> r1;
        if(root->data != x) r1= printInRange(x, y, root->left);
        vector<int> r2;
        if(root->data != y) r2= printInRange(x, y, root->right);

        r1.insert(r1.end(), r2.begin(), r2.end()); // r1 = r1+r2
        res.insert(res.end(), r1.begin(), r1.end()); // res = res+r1
    }
    else if(root->data > y) res= printInRange(x, y, root->left);
    else res= printInRange(x, y, root->right);

    return res;
}

vector<vector<int>> rootToLeafPaths(Node* root){
    vector<vector<int>> paths;
    if(root==nullptr) return paths;

    if(root->left != nullptr && root->right != nullptr){ // having both childs
        vector<vector<int>> v1= rootToLeafPaths(root->left);
        vector<vector<int>> v2= rootToLeafPaths(root->right);
        // v1= v1+v2
        for(auto &row: v2) v1.push_back(row);
        paths= v1;
        for(auto &row: paths) row.insert(row.begin(), root->data);
    }
    else if(root->left != nullptr || root->right != nullptr){ // only one child
        if(root->left != nullptr) paths= rootToLeafPaths(root->left);
        else paths= rootToLeafPaths(root->right);
        for(auto &row: paths) row.insert(row.begin(), root->data);
    }
    else{ // leaf node
        vector<int> v(1, root->data);
        paths.push_back(v);
    }

    return paths;
}

int main(){

    vector<int> v= {8,5,3,1,4,6,10,11,14};
    BST bst;
    for(int ele: v) bst.insert(ele);
    inorder(bst.root);
    cout<< endl;
    // Node* target= bst.search(11, bst.root);
    // if(target) cout<< true;
    // else cout<< false;

    // bst.root= bst.remove(4, bst.root);
    // inorder(bst.root);

    // vector<int> res= printInRange(6, 10, bst.root);
    // for(int ele: res) cout<< ele<<" ";

    vector<vector<int>> paths= rootToLeafPaths(bst.root);
    for(auto &row: paths){
        for(int ele: row) cout<<ele<<" ";
        cout<< endl;
    }

return 0;    
}
