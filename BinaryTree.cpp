#include <iostream>
using namespace std;
#include <cmath>
#include <string>
#include <time.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <bits/stdc++.h>

void swap(int* a, int* b){
    int temp= *a;
    *a= *b;
    *b= temp;
}

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create()
{// basically returing the pointer to the new_node that is being created
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node)); // VVImp***
    int x;
    printf("Enter data to node: ");
    scanf("%d", &x);
    if(x==-1)
        return NULL;
    new_node->data= x;

    printf("Enter for Left Child of %d\n", new_node->data);
    new_node->left= create();
    printf("Enter for Right Child of %d\n", new_node->data);
    new_node->right= create();

    return new_node;

}

void preorder(struct Node* root)
{
    if(root==NULL)
        return;
    printf("%d ", root->data); // Print the current node
    
    // Traverse left subtree
    preorder(root->left);  
    // Traverse right subtree
    preorder(root->right);

}

void inorder(struct Node* root)
{
    if(root== NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root)
{
    if(root== NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void morrisTraversalInorder(struct Node* root)
{
    struct Node* curr= root;
    struct Node* leftNode= NULL; // leftNode k right most child ko curr se connect karo
    while(curr!=NULL)
    {
        if(curr->left==NULL){
            printf("%d ", curr->data);
            curr= curr->right;
        }
        else{
            leftNode= curr->left;
            while(leftNode->right!=NULL && leftNode->right!=curr)
                leftNode= leftNode->right;

            if(leftNode->right==curr){
                leftNode->right= NULL;
                printf("%d ", curr->data);
                curr= curr->right;
            }
            else{
                leftNode->right= curr;
                curr= curr->left; 
            }
        }
    }
}

void morrisTraversalPreorder(struct Node* root)
{
    // print-> when left child is null or when a new thread is created then print the curr node
    // move leftNode to the right most posn to create a new thread
    // when to move to right subtree-> when left child is null or left subtree is completely processed
    struct Node* curr= root;
    struct Node* leftNode= NULL;
    while(curr!=NULL){
        if(curr->left==NULL){
            printf("%d ", curr->data);
            curr= curr->right;
            continue;
        }
        leftNode= curr->left;
        while(leftNode->right!=NULL && leftNode->right!=curr) leftNode= leftNode->right;
        if(leftNode->right==NULL){
            leftNode->right= curr;
            printf("%d ", curr->data);
            curr= curr->left;
            continue;
        }
        leftNode->right= NULL;
        curr= curr->right;
    }
}

int main(){

    // Binary Tree in C
    
    struct Node* root= create(); // returning the root element pointer
    // printf("%d ", root->left->data);
    morrisTraversalInorder(root);
    morrisTraversalPreorder(root);

return 0;
}