#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void insert_begin(int ele);
void insert_end(int ele);
void insert_middle(int ele,int pos);
void delete_begin();
void delete_end();
void delete_middle(int ele);
void display();
void display_reverse();
void sort_list();
int numberofnodes();
void removeloop();

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

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
    temp2=temp2->next;
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
        insert_begin(ele);
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

void delete_begin()
{
    head=head->next;
}

void delete_end()
{
    if(head==NULL || head->next==NULL)
    {
        head=NULL;
        return;
    }
    struct node *temp1=head;
    while(temp1->next->next!=NULL)
    temp1=temp1->next;
    temp1->next=NULL;
}

void delete_middle(int ele)
{
    struct node *temp1=head,*temp2;
    if(temp1->data==ele)
    {
        delete_begin();
        return;
    }
    while(temp1!=NULL && temp1->data!=ele)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    if(temp1==NULL)
    return;
    temp1=temp1->next;
    temp2->next=temp1;
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

void display_reverse()
{
    struct node *temp=head,*temp_prev=NULL,*temp_next=NULL;
    while(temp!=NULL)
    {
        temp_next=temp->next;
        temp->next=temp_prev;
        temp_prev=temp;
        temp=temp_next;
    }
    head=temp_prev;
    display();
}

int numberofnodes()
{
    struct node *temp=head;
    int count=0;
    if(temp==NULL)
    count=0;
    else
    {
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
    }
    printf("Number of Nodes = %d",count);
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

void removeloop()
{
    if(head==NULL || head->next==NULL)
    return;
    if(head->next==head)
    {
        head->next = NULL;
        return ;
    }
    struct node* slow = head;
    struct node* fast = head; 
    while(fast!=NULL && slow!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow)
        break;
    }
    if(fast==NULL || fast->next==NULL)
    return;
    slow=head;
    while(fast!=slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    while(slow->next!=fast)
    slow=slow->next;
    slow->next = NULL;
    return;
}   