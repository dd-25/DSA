#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *create_node(int ele)
{
    struct tree *node=(struct tree*)malloc(sizeof(struct tree));
    node->data=ele;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void link(struct tree *root,struct tree *left,struct tree *right)
{
    root->left=left;
    root->right=right;
}

void inorder(struct tree *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    return;
}

void preorder(struct tree *root)
{
    if(root==NULL)
    return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
    return;
}

void postorder(struct tree *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
    return;
}

int main()
{
    struct tree *root=create_node(2);
    struct tree *left=create_node(1);
    struct tree *right=create_node(3);
    link(root,left,right);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}