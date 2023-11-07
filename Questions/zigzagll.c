#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insert_end(struct Node *head, int value)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
    head=temp;
    else
    {
        struct Node *p=head;
        while (p->next!=NULL)
        p=p->next;
        p->next=temp;
    }
    return head;
}

void printll(struct Node *head)
{
    while (head!=NULL)
    {
        printf("%d  ", head->data);
        head=head->next;
    }
    printf("\n");
    return;
}

struct Node *insert_begin(struct Node *head, int value)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
    head=temp;
    else
    {
        temp->next=head;
        head=temp;
    }
    return head;
}

void zigzag(struct Node *head, struct Node *a[], int k)
{
    struct Node *temp=head;
    int i=0,j=1,f=0;
    while (temp!=NULL)
    {
        int val=temp->data;
        if(f==0)
        {
            a[i]=insert_end(a[i], val);
            j++;
        }
        if(f==1)
        {
            a[i]=insert_begin(a[i], val);
            j++;
        }
        if(j>k)
        {
            i++;
            j=1;
            f=!f;
        }
        temp=temp->next;
    }
    return;
}

struct Node *multiply(struct Node *a[], int k, int count)
{
    struct Node *result=NULL;
    int i=0, p=1;
    while (p <= count)
    {
        int mul=1;
        for(i=0;i<k;i++)
        {
            mul *= a[i]->data;
            a[i]=a[i]->next;
        }
        result=insert_end(result, mul);
        p++;
    }
    return result;
}

int main()
{
    int n;
    struct Node *head=NULL;
    scanf("%d", &n);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d", &x);
        head=insert_end(head, x);
    }
    int k;
    scanf("%d", &k);
    struct Node *a[100]={NULL};
    zigzag(head,a,n/k);
    struct Node *ans=NULL;
    ans=multiply(a,k,n/k);
    printll(ans);
    return 0;
}