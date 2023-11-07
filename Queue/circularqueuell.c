#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct queue
{
    int data;
    struct queue *next;
};

bool isempty(struct queue *queue)
{
    return queue==NULL;
}

void enqueue(struct queue **queue,int ele)
{
    if(isempty(*queue))
    {
        (*queue)=(struct queue*)malloc(sizeof(struct queue));
        (*queue)->data=ele;
        (*queue)->next=(*queue);
        return;
    }
    struct queue *temp=(struct queue*)malloc(sizeof(struct queue));
    temp->data=ele;
    temp->next=(*queue);
    struct queue *temp1=(*queue);
    while(temp1->next!=(*queue))
    temp1=temp1->next;
    temp1->next=temp;
    return;
}

void dequeue(struct queue **queue)
{
    if(isempty(*queue))
    {
        printf("Queue is already empty\n");
        return;
    }
    if((*queue)->next==(*queue))
    {
        (*queue)=NULL;
        return;
    }
    struct queue *temp1=(*queue);
    while(temp1->next!=(*queue))
    temp1=temp1->next;
    (*queue)=(*queue)->next;
    temp1->next=(*queue);
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
    enqueue(&queue,1);
    printf("%d\n",front(&queue));
    enqueue(&queue,2);
    printf("%d\n",front(&queue));
    enqueue(&queue,3);
    printf("%d\n",front(&queue));
    dequeue(&queue);
    printf("%d\n",front(&queue));
    dequeue(&queue);
    printf("%d\n",front(&queue));
    dequeue(&queue);
    printf("%d\n",front(&queue));
    dequeue(&queue);
    printf("%d\n",front(&queue));
    return 0;
}