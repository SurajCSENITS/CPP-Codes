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

bool isSymmetric(TreeNode* root){
    if(root==NULL) return false;

    queue<struct TreeNode*> ql;
    queue<struct TreeNode*> qr;
    ql.push(root);
    qr.push(root);

    while(ql.size()!=0 && qr.size()!=0){
        if(ql.front()==NULL && qr.front()!=NULL) return false;
        if(ql.front()!=NULL && qr.front()==NULL) return false;
        if(ql.front()==NULL && qr.front()==NULL){
            ql.pop();
            qr.pop();
            continue;
        }

        struct TreeNode* templ= ql.front(); ql.pop();
        struct TreeNode* tempr= qr.front(); qr.pop();

        if(templ->val!=tempr->val) return false;
        ql.push(templ->left); ql.push(templ->right);
        qr.push(tempr->right); qr.push(tempr->left);
    }
    return true;
}


int main(){

    struct TreeNode* root= create();
    cout<< isSymmetric(root);

return 0;    
}
