#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert_begin(int ele);
void insert_end(int ele);
void insert_middle(int ele,int pos);
void delete_begin();
void delete_end();
void delete_middle(int ele);
void sort_list();
void display();
void display_reverse();
int numberofnodes();

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* head=NULL;

int main()
{
    insert_begin(1);
    display();
    insert_end(10);
    display();
    insert_middle(7,3);
    display();
    insert_middle(6,3);
    display();
    insert_middle(9,4);
    display();
    sort_list();
    insert_middle(8,5);
    display();
    delete_begin();
    display();
    delete_end();
    display();
    delete_middle(7);
    display();
    display_reverse();
    sort_list();
    numberofnodes();
    return 0;
}

void insert_begin(int ele)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=head;
    temp->prev=NULL;
    if(head!=NULL)
    head->prev=temp;
    head=temp;
}
void insert_end(int ele)
{
    struct node* temp=head;
    struct node* temp1;
    temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=ele;
    temp1->next=NULL;
    while(temp->next!=NULL)
    temp=temp->next;
    temp1->prev=temp;
    temp->next=temp1;
}

void insert_middle(int ele,int pos)
{
    if(pos==1)
    {
        insert_begin(ele);
        return;
    }
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;
    temp->prev=NULL;
    struct node* temp1=head;
    int count=1;
    while(temp1->next!=NULL && count<pos-1)
    {
        temp1=temp1->next;
        count++;
    }
    if(temp1->next!=NULL)
    temp1->next->prev=temp;
    temp->prev=temp1;
    temp->next=temp1->next;
    temp1->next=temp;
}

void delete_begin()
{
    head=head->next;
    head->prev=NULL;
}

void delete_end()
{
    struct node* temp=head;
    while(temp->next->next!=NULL)
    temp=temp->next;
    temp->next=NULL;
}

void delete_middle(int ele)
{
    struct node* temp=head;
    if(temp->data==ele)
    {
        delete_begin();
        return;
    }
    while(temp->data!=ele && temp->next!=NULL)
    temp=temp->next;
    if(temp->next==NULL)
    {
        delete_end();
        return;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
}

int numberofnodes()
{
    struct node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("Number of Nodes = %d\n",count);
}

void display()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void display_reverse()
{
    struct node* temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void sort_list()
{
    struct node* temp1=head;
    struct node* temp2;
    struct node* temp3=head;
    while(temp1!=NULL)
    {
        temp2=temp1->next;
        while(temp2!=NULL)
        {
            if(temp1->data>temp2->data)
            {
                int temp;
                temp=temp2->data;
                temp2->data=temp1->data;
                temp1->data=temp;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    while(temp3!=NULL)
    {
        printf("%d ",temp3->data);
        temp3=temp3->next;
    }
    printf("\n");
}