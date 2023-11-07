#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void insert_begin(int ele);
void insert_end(int ele);
void insert_middle(int ele,int pos);
void display();
void sort_list();
int numberofnodes();

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

int main()
{
    insert_begin(1);
    insert_end(10);
    insert_middle(7,3);
    insert_middle(6,3);
    insert_middle(9,4);
    insert_middle(8,5);
    printf("Unsorted list\n");
    display();
    sort_list();
    return 0;
}

void insert_begin(int ele)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=head;
    head=temp;
}

void insert_end(int ele)
{
    struct node *temp1;
    temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=ele;
    temp1->next=NULL;
    if(head==NULL)
    {
        head=temp1;
        return;
    }
    struct node *temp2=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

void insert_middle(int ele,int pos)
{
    struct node *temp3;
    temp3=(struct node*)malloc(sizeof(struct node));
    temp3->data=ele;
    temp3->next=NULL;
    if(pos==1)
    {
        temp3->next=head;
        head=temp3;
        return;
    }
    int count=1;
    struct node *temp4=head;
    while(temp4!=NULL && count<pos-1)
    {
        temp4=temp4->next;
        count++;
    }
    temp3->next=temp4->next;
    temp4->next=temp3;
}

void display()
{
    struct node *temp2=head;
    while(temp2!=NULL)
    {
        printf("%d ",temp2->data);
        temp2=temp2->next;
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
    printf("Sorted list\n");
    while(temp3!=NULL)
    {
        printf("%d ",temp3->data);
        temp3=temp3->next;
    }
    printf("\n");
}