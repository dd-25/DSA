#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
};

void insert(struct bst **root,int ele)
{
    if(*root==NULL)
    {
        *root=(struct bst*)malloc(sizeof(struct bst));
        (*root)->data=ele;
        (*root)->left=NULL;
        (*root)->right=NULL;
        return;
    }
    struct bst *trav=*root,*prev=NULL;
    bool dir=0;
    while(trav)
    {
        prev=trav;
        if(ele<trav->data)
        trav=trav->left;
        else if(ele>trav->data)
        {
            trav=trav->right;
            dir=1;
        }
        else
        return;
    }
    if(dir)
    {
        prev->right=(struct bst*)malloc(sizeof(struct bst));
        prev->right->data=ele;
        prev->right->left=NULL;
        prev->right->right=NULL;
    }
    else
    {
        prev->left=(struct bst*)malloc(sizeof(struct bst));
        prev->left->data=ele;
        prev->left->left=NULL;
        prev->left->right=NULL;
    }
    return;
}

void inorder(struct bst *root)
{
    struct node *trav=root;
    return;
}

int main()
{
    struct bst *root=NULL;
    printf("Enter the number of elements\n");
    int n;
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        insert(&root,x);
    }
    inorder(root);
    return 0;
}