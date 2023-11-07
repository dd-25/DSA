#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* tail=NULL;

void insert_begin(int ele)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        temp->next=head;
        return;
    }
    temp->next=head;
    head=temp;
    tail->next=head;
}

void insert_end(int ele)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    tail->next=temp;
    tail=temp;
    tail->next=head;
}

void insert_middle(int ele,int pos)
{
    struct node* temp;
    struct node* temp1=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    if(pos==1)
    {
        insert_begin(ele);
        return;
    }
    int count=1;
    while(temp1!=tail && count<pos-1)
    {
        temp1=temp1->next;
        count++;
    }
    temp->next=temp1->next;
    temp1->next=temp;
}

void delete_begin()
{
    struct node* temp=head;
    head=head->next;
    tail->next=head;
}

void delete_end()
{
    struct node* temp=head;
    while(temp->next!=tail)
    temp=temp->next;
    tail=temp;
    tail->next=head;
}

void delete_middle(int ele)
{
    struct node* temp=head;
    if(temp->data==ele)
    {
        delete_begin();
        return;
    }
    while(temp->next->data!=ele && temp!=tail)
    temp=temp->next;
    temp->next=temp->next->next;
}

void display()
{
    struct node* temp=head;
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
    printf("\n");
}

void reverse()
{
    struct node* temp=head;
    struct node* temp_prev=tail;
    struct node* temp_next=tail;
    do
    {
        temp_next=temp->next;
        temp->next=temp_prev;
        temp_prev=temp;
        temp=temp_next;
    }
    while(temp_prev!=tail);
    head=temp_prev;
    tail=temp_next;
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
                int temp=temp2->data;
                temp2->data=temp1->data;
                temp1->data=temp;
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
    insert_begin(3);
    display();
    insert_end(5);
    display();
    insert_middle(7,2);
    display();
    insert_middle(8,2);
    display();
    insert_middle(15,4);
    display();
    insert_middle(25,4);
    display();
    insert_middle(12,2);
    display();
    insert_middle(4,2);
    display();
    insert_middle(9,2);
    display();
    insert_middle(10,2);
    display();
    insert_middle(1,4);
    display();
    delete_begin();
    display();
    delete_end();
    display();
    delete_middle(8);
    display();
    reverse();
    display();
    sort_list();
    display();
    numberofnodes();
    return 0;
}