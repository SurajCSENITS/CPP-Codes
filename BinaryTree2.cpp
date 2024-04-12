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


class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data= val;
        left= nullptr;
        right= nullptr;
    }
};

class BinaryTree{ // Apna college : https://youtu.be/-DzowlcaUmE
public:
    int idx;
    BinaryTree(){ idx= -1; }
       
    Node* buildPreorder(vector<int>& v){ // after creating the tree returning the root
        idx++;
        if(v[idx]==-1) return nullptr;
        Node* root= new Node(v[idx]);
        root->left= buildPreorder(v);
        root->right= buildPreorder(v);
        return root;
    }

    vector<vector<int>> levelOrder(Node* root){ // level wise vectored output
        vector<vector<int>> answer;
        // Corner Case
        if(root==NULL) return answer;

        queue<Node*> q;
        q.push(root); q.push(nullptr);
        vector<int> level;
        while(!q.empty()){
            level.push_back(q.front()->data);
            if(q.front()->left!=nullptr) q.push(q.front()->left);
            if(q.front()->right!=nullptr) q.push(q.front()->right);
            q.pop();

            if(q.front()==nullptr){ // level is completed
                answer.push_back(level);
                level.clear();
                q.pop();
                if(!q.empty()) q.push(nullptr);
            }
        }
        return answer;
    }

    int countNodes(Node* root){ // preorder
        if(root==nullptr) return 0;
        // count leftSubtree nodes
        int count_left= countNodes(root->left);
        // count rightSubtree nodes
        int count_right= countNodes(root->right);
        int totalNodes= 1+count_left+count_right;
        return totalNodes;
    }

    int height(Node* root){ // height/deep/level of single root is 1
        if(root==nullptr) return 0;
        // max deep in leftsubtree
        int left_deep= height(root->left);
        // max deep in rightsubtree
        int right_deep= height(root->right);
        int max_deep= 1+max(left_deep, right_deep);
        return max_deep;
    }

    int diameter(Node* root){ // o(n^2)
        // There are only three cases of a diameter
        // 1. lies on leftsubtree
        // 2. lies on right subtree
        // 3. lies through the root
        if(root==nullptr) return 0;
        int left_node_dia= diameter(root->left);
        int right_node_dia= diameter(root->right);
        int curr_node_dia= height(root->left)+height(root->right)+1;
        int dia= max(curr_node_dia, max(left_node_dia, right_node_dia));
        return dia;
    }

    pair<int, int> diameter2(Node* root){ // returning {height, diameter} wrt each node
        // There are only three cases of a diameter
        // 1. lies on leftsubtree
        // 2. lies on right subtree
        // 3. lies through the root
        if(root==nullptr) return {0, 0};
        pair<int, int> left_info= diameter2(root->left);
        pair<int, int> right_info= diameter2(root->right);
        int dia_through_curr_root= left_info.first+right_info.first+1; 
        pair<int, int> curr_root_info= {max(left_info.first, right_info.first)+1, max(dia_through_curr_root, max(left_info.second, right_info.second))};
        return curr_root_info;
    }

    void preorder(Node* root, vector<int>& v){
        if(root==nullptr){
            v.push_back(-1);
            return;
        }          
        v.push_back(root->data);
        // Traverse left subtree
        preorder(root->left, v);  
        // Traverse right subtree
        preorder(root->right, v);
    }

    bool isSubtree(Node* root, Node* subroot){
        if(root==nullptr) return false;

        if(root->data==subroot->data){
            // compare the preorder traversal of both roots
            vector<int> root_preorder;
            preorder(root, root_preorder);
            vector<int> subroot_preorder;
            preorder(subroot, subroot_preorder);
            if(root_preorder==subroot_preorder) return true;
        }
        // check at left and right subtree
        return isSubtree(root->left, subroot) or isSubtree(root->right, subroot);
    }

    bool isEqualtree(Node* root, Node* subroot){
        if(root==nullptr and subroot==nullptr) return true;
        if(root==nullptr || subroot==nullptr) return false;
        if(root->data!=subroot->data) return false;
        return isEqualtree(root->left, subroot->left) and isEqualtree(root->right, subroot->right);
    }

    bool isSubtree2(Node* root, Node* subroot){
        if(root==nullptr) return false;

        if(root->data==subroot->data) if(isEqualtree(root, subroot)) return true;       

        return isSubtree2(root->left, subroot) or isSubtree2(root->right, subroot);
    }

    vector<int> levelSum(Node* root){
        vector<int> level_sum(1, 0); // v[i] -> ith level's sum
        // corner case
        if(root==nullptr) return level_sum;

        queue<Node*> q;
        q.push(root); q.push(nullptr);
        int sum= 0;
        while(!q.empty()){
            sum+= q.front()->data;
            if(q.front()->left != nullptr) q.push(q.front()->left);
            if(q.front()->right != nullptr) q.push(q.front()->right);
            q.pop(); 

            if(q.front()==nullptr){ // one level completed
                level_sum.push_back(sum);
                sum= 0;
                q.pop();
                if(!q.empty()) q.push(nullptr);
            }
        }
        return level_sum;
    }
};

int main(){

    vector<int> v= {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    BinaryTree tree;
    Node* root= tree.buildPreorder(v);
    // vector<vector<int>> answer= tree.levelOrder(root);
    // for(vector<int>& row: answer){
    //     for(int ele: row) cout<< ele<<" ";
    //     cout<< endl;
    // }
    // cout<< tree.countNodes(root)<<endl; 
    // cout<< tree.height(root)<<endl;
    // cout<< tree.diameter(root)<<endl;
    // pair<int, int> tree_info= tree.diameter2(root);
    // cout<< tree_info.second<< endl;
    // tree.idx= -1;
    // vector<int> root_nodes= {3,4,1,-1,-1,2,-1,-1,5,-1,-1};
    // Node* root= tree.buildPreorder(root_nodes);
    // tree.idx= -1;
    // vector<int> subroot_nodes= {4,1,-1,-1,2,-1,-1};
    // Node* subroot= tree.buildPreorder(subroot_nodes);
    // return tree.isSubtree(root, subroot);
    vector<int> level_sum= tree.levelSum(root);
    for(int ele: level_sum) cout<< ele<<" ";

return 0;
}