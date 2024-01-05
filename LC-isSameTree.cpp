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

bool isSameTree(TreeNode* p, TreeNode* q){ // inspired by level order traversal
    if(p==NULL && q==NULL) return true;
    if(p==NULL && q!=NULL) return false;
    if(p!=NULL && q==NULL) return false;

    queue<struct TreeNode*> qp;
    queue<struct TreeNode*> qq;
    qp.push(p);
    qq.push(q);
    while(!qp.empty() && !qq.empty()){
        struct TreeNode* tempp= qp.front();
        struct TreeNode* tempq= qq.front();
        qp.pop();
        qq.pop();
        if(tempp->val!=tempq->val) return false;
        if(tempp->right!=NULL && tempq->right==NULL) return false;
        if(tempq->right!=NULL && tempp->right==NULL) return false;

        if(tempp->left!=NULL) qp.push(tempp->left);
        if(tempp->right!=NULL) qp.push(tempp->right);
        if(tempq->left!=NULL) qq.push(tempq->left);
        if(tempq->right!=NULL) qq.push(tempq->right);
    }
    
    if(qp.size()==0 && qq.size()!=0) return false;
    if(qq.size()==0 && qp.size()!=0) return false;

    return true;

}



int main(){

    

return 0;    
}
