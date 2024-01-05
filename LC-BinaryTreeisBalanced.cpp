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



struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* create()
{
    struct TreeNode* new_node= (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int x;
    printf("Enter data to node: ");
    scanf("%d", &x);
    if(x==-1)
        return NULL;
    new_node->val= x;

    printf("Enter for Left Child of %d\n", new_node->val);
    new_node->left= create();
    printf("Enter for Right Child of %d\n", new_node->val);
    new_node->right= create();

    return new_node;

}

int subtreeDepth(TreeNode* root){
    if(root==NULL) return -1;

    int level= 0;
    queue<struct TreeNode*> q;
    q.push(root);
    while(1){
        int size= q.size();
        if(size==0) return level-1; // depth= level-1
        
        while(size>0){       
            struct TreeNode* temp= q.front();
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            size--;
        }
        level++;
    }
    return level-1;
}

bool isBalanced(TreeNode* root){
    if(root==NULL) return true;
    if(abs(subtreeDepth(root->left)-subtreeDepth(root->right))>1) return false;
    if(isBalanced(root->left) && isBalanced(root->right)) return true;
    return false;
}

int main(){

    struct TreeNode* root= create();
    cout<< isBalanced(root);

return 0;    
}
