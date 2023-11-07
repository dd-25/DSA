#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct dequeue
{
    int data;
    struct dequeue *next;
};

bool isempty(struct dequeue **dequeue)
{
    return (*dequeue)==NULL;
}

void enqueuefront(struct dequeue **dequeue,int ele)
{
    struct dequeue *temp=(struct dequeue*)malloc(sizeof(struct dequeue));
    temp->data=ele;
    temp->next=(*dequeue);
    (*dequeue)=temp;
    return;
}

void enqueuerear(struct dequeue **dequeue,int ele)
{
    struct dequeue *temp=(struct dequeue*)malloc(sizeof(struct dequeue));
    temp->data=ele;
    temp->next=NULL;
    if(isempty(dequeue))
    {
        (*dequeue)=temp;
        return;
    }
    struct dequeue *temp1=(*dequeue);
    while(temp1->next!=NULL)
    temp1=temp1->next;
    temp1->next=temp;
    return;
}

void dequeuefront(struct dequeue **dequeue)
{
    if(isempty(dequeue))
    {
        printf("Dequeue is already empty\n");
        return;
    }
    (*dequeue)=(*dequeue)->next;
    return;
}

void dequeuerear(struct dequeue **dequeue)
{
    if(isempty(dequeue))
    {
        printf("Dequeue is already empty\n");
        return;
    }
    if((*dequeue)->next==NULL)
    {
        (*dequeue)=NULL;
        return;
    }
    struct dequeue *temp=(*dequeue);
    while(temp->next->next!=NULL)
    temp=temp->next;
    temp->next=NULL;
    return;
}

int front(struct dequeue **dequeue)
{
    if(isempty(dequeue))
    {
        printf("Dequeue is already empty\n");
        return 0;
    }
    return (*dequeue)->data;
}

int rear(struct dequeue **dequeue)
{
    if(isempty(dequeue))
    {
        printf("Dequeue is already empty\n");
        return 0;
    }
    struct dequeue *temp=(*dequeue);
    while(temp->next!=NULL)
    temp=temp->next;
    return temp->data;
}

int main()
{
    struct dequeue *dequeue=NULL;
    enqueuefront(&dequeue,1);
    printf("%d\n",front(&dequeue));
    enqueuefront(&dequeue,7);
    printf("%d\n",front(&dequeue));
    enqueuerear(&dequeue,5);
    printf("%d\n",rear(&dequeue));
    enqueuerear(&dequeue,10);
    printf("%d\n",rear(&dequeue));
    dequeuefront(&dequeue);
    printf("%d\n",front(&dequeue));
    dequeuefront(&dequeue);
    printf("%d\n",front(&dequeue));
    dequeuerear(&dequeue);
    printf("%d\n",rear(&dequeue));
    dequeuerear(&dequeue);
    printf("%d\n",rear(&dequeue));
    return 0;
}