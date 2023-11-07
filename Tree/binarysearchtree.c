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

int max(int a,int b)
{
    return a>b?a:b;
}

struct tree *create_node(int ele)
{
    struct tree *node=(struct tree*)malloc(sizeof(struct tree));
    node->data=ele;
    node->left=NULL;
    node->right=NULL;
    return node;
}

// void link(struct tree *root,struct tree *left,struct tree *right)
// {
//     root->left=left;
//     root->right=right;
//     return;
// }

void inorder(struct tree *root)
{
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
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

void recursive_bst(struct tree *root,int ele)
{
    if(ele<root->data)
    {
        if(root->left!=NULL)
        recursive_bst(root->left,ele);
        else
        {
            struct tree *new=create_node(ele);
            root->left = new;
            return;
        }
    }
    else if(ele>root->data)
    {
        if(root->right!=NULL)
        recursive_bst(root->right,ele);
        else
        {
            struct tree *new = create_node(ele);
            root->right = new;
            return;
        }
    }
    else
    {
        printf("Element already exists\n");
        return;
    }
}

void iterative_bst(struct tree *root,int ele)
{
    struct tree *prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(ele<root->data)
        root=root->left;
        else if(ele>root->data)
        root=root->right;
        else
        {
            printf("Element already exists\n");
            return;
        }
    }
    struct tree *new=create_node(ele);
    if(ele<prev->data)
    prev->left=new;
    else
    prev->right=new;
    return;
}

void recursive_search(struct tree *root,int ele)
{
    if(root==NULL)
    {
        printf("Element not found\n");
        return;
    }
    if(ele<root->data)
    recursive_search(root->left,ele);
    else if(ele>root->data)
    recursive_search(root->right,ele);
    else
    {
        printf("Element found\n");
        return;
    }
}

void iterative_search(struct tree *root,int ele)
{
    while(root!=NULL)
    {
        if(root->data==ele)
        {
            printf("Element found\n");
            return;
        }
        else if(ele<root->data)
        root=root->left;
        else if(ele>root->data)
        root=root->right;
    }
    printf("Element not found\n");
    return;
}

//Write code for deletion of a node in BST

int depth(struct tree *root,int ele)
{
    if(root==NULL)
    {
        printf("Element not found\n");
        return -1;
    }
    if(ele<root->data)
    {
        int leftdepth=1+depth(root->left,ele);
        return leftdepth;
    }
    else if(ele>root->data)
    {
        int rightdepth=1+depth(root->right,ele);
        return rightdepth;
    }
    else
    return 0;
}

int height(struct tree *root)
{
    if(root==NULL)
    return -1;
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return 1+max(leftheight,rightheight);
}

void delete(struct tree *root,int ele)
{
    struct tree *troot=root;
    if(ele==troot->data)
    {
        while(troot->right->right)
        {
            troot=troot->right;
        }
        root->data=troot->left->data;
        troot->left=NULL;
        return;
    }
    struct tree *prev=troot;
    bool dir=0;
    while(troot!=NULL || troot->data!=ele)
    {
        prev=troot;
        if(ele<troot->data)
        {
            troot=troot->left;
            dir=0;
        }
        else if(ele>troot->data)
        {
            troot=troot->right;
            dir=1;
        }
    }
    if(troot->right==NULL && troot->left==NULL)
    {
        if(dir)
        prev->right=NULL;
        else
        prev->left=NULL;
    }
    else if(troot->right==NULL)
    {
        if(dir)
        prev->right=troot->left;
        else
        prev->left=troot->left;
    }
    else if(troot->left==NULL)
    {
        if(dir)
        prev->right=troot->right;
        else
        prev->left=troot->right;
    }
    else
    {
        struct tree *node=troot;
        while(troot->right->right)
        {
            troot=troot->right;
        }
        node->data=troot->left->data;
        troot->left=NULL;
    }
    return;
}

int main()
{
    struct tree *root1=create_node(5);
    struct tree *root2=create_node(10);
    printf("Enter the number of elements\n");
    int n;
    scanf("%d",&n);
    printf("Enter the elements for recursive BST\n");
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        recursive_bst(root1,x);
    }
    printf("Recursive BST\n");
    inorder(root1);
    printf("\n");
    printf("Enter the elements for iterative BST\n");
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        iterative_bst(root2,x);
    }
    printf("Iterative BST\n");
    inorder(root2);
    printf("\n");
    int k;
    printf("Enter the number you want to search\n");
    scanf("%d",&k);
    recursive_search(root1,k);
    iterative_search(root2,k);
    printf("Height of tree is %d\n",height(root1));
    printf("Enter the number whose depth is to be checked\n");
    int j;
    scanf("%d",&j);
    printf("Depth of tree is %d",depth(root2,j));
    return 0;
}