#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head=NULL;
struct node* tail=NULL;

void insert_begin(int ele)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    if(head==NULL)
    {
        head=temp;
        tail=head;
        temp->next=head;
        temp->prev=tail;
        return;
    }
    tail->next=temp;
    temp->next=head;
    head->prev=temp;
    temp->prev=tail;
    head=temp;
}

void insert_end(int ele)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=head;
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
    head->prev=tail;
}

void insert_middle(int ele,int pos)
{
    struct node* temp=head;
    struct node* temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=ele;
    if(pos==1)
    {
        insert_begin(ele);
        return;
    }
    int count=1;
    while(temp!=head && count<pos-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp==head)
    return;
    if(temp==tail)
    {
        insert_end(ele);
        return;
    }
    temp1->next=temp->next;
    temp->next=temp1;
    temp1->prev=temp;
    temp1->next->prev=temp1;
}

void delete_begin()
{
    head=head->next;
    tail->next=head;
    head->prev=tail;
}

void delete_end()
{
    tail=tail->prev;
    tail->next=head;
    head->prev=tail;
}

void delete_middle(int ele)
{
    struct node* temp=head;
    if(head->data==ele)
    {
        delete_begin(ele);
        return;
    }
    while(temp!=tail && temp->data!=ele)
    temp=temp->next;
    if(temp==tail && temp->data==ele)
    {
        delete_end();
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
}

void dislay()
{
    struct node* temp=head;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
    printf("\n");
}

void reverse_display()
{
    struct node* temp=tail;
    do
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    while(temp!=tail);
    printf("\n");
}

void sort_list()
{
    struct node* temp1=head;
    struct node* temp2;
    do
    {
        temp2=temp1->next;
        do
        {
            if(temp1->data>temp2->data)
            {
                int temp=temp1->data;
                temp1->data=temp2->data;
                temp2->data=temp;
            }
            temp2=temp2->next;
        }
        while(temp2!=head);
        temp1=temp1->next;
    }
    while(temp1!=tail);
}

int numberofnodes()
{
    struct node* temp=head;
    int count=0;
    do
    {
        temp=temp->next;
        count++;
    }
    while(temp!=head);
    printf("Number of Nodes = %d\n",count);
}

int main()
{
    insert_begin(1);
    dislay();
    insert_end(10);
    dislay();
    insert_middle(2,2);
    dislay();
    insert_middle(3,2);
    dislay();
    insert_middle(8,2);
    dislay();
    insert_middle(9,4);
    dislay();
    insert_middle(5,3);
    dislay();
    insert_middle(7,6);
    dislay();
    insert_middle(11,5);
    dislay();
    delete_begin();
    dislay();
    delete_end();
    dislay();
    delete_middle(5);
    dislay();
    reverse_display();
    sort_list();
    dislay();
    numberofnodes();
    return 0;
}