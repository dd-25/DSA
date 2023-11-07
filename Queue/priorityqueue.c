#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct queue
{
    int data;
    int priority;
    struct queue *next;
};

bool isempty(struct queue *queue)
{
    return queue==NULL;
}

void enqueue(struct queue **queue,int ele, int p)
{
    struct queue *temp=(struct queue*)malloc(sizeof(struct queue));
    temp->data=ele;
    temp->priority=p;
    if(isempty(*queue) || (*queue)->priority>p)
    {
        temp->next=(*queue);
        (*queue)=temp;
        return;
    }
    struct queue *temp1=(*queue);
    while(temp1->next->priority < p && temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    if(temp1->next->priority==p && temp1->next->data>temp->data)
    {
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
    return;
}

void dequeue(struct queue **queue,int p)
{
    if(isempty(*queue))
    {
        printf("Queue is already empty\n");
        return;
    }
    if((*queue)->priority==p)
    {
        *queue=(*queue)->next;
        return;
    }
    struct queue *temp=*queue;
    while(temp!=NULL)
    {
        if(temp->next->priority==p)
        {
            temp->next=temp->next->next;
            break;
        }
        temp=temp->next;
    }
    return;
}

int front(struct queue **queue)
{
    if(isempty(*queue))
    return 0;
    return (*queue)->data;
}

int main()
{
    struct queue *queue=NULL;
    enqueue(&queue,1,3);
    printf("%d\n",front(&queue));
    enqueue(&queue,2,2);
    printf("%d\n",front(&queue));
    enqueue(&queue,3,3);
    printf("%d\n",front(&queue));
    dequeue(&queue,2);
    printf("%d\n",front(&queue));
    dequeue(&queue,3);
    printf("%d\n",front(&queue));
    dequeue(&queue,3);
    printf("%d\n",front(&queue));
    dequeue(&queue,1);
    printf("%d\n",front(&queue));
    return 0;
}