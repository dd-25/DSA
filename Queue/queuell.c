#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct queue
{
    int data;
    struct queue* next;
};

bool isempty(struct queue* queue)
{
    return queue==NULL;
}

void enqueue(struct queue** queue,int ele)
{
    struct queue* traverse=*queue;
    if(isempty(traverse))
    {
        *queue=(struct queue*)malloc(sizeof(struct queue));
        (*queue)->data=ele;
        (*queue)->next=NULL;
        return;
    }
    while(traverse->next!=NULL)
    traverse=traverse->next;
    traverse->next=(struct queue*)malloc(sizeof(struct queue));
    traverse->next->data=ele;
    traverse->next->next=NULL;
    return;
}

void dequeue(struct queue** queue)
{
    if(!isempty(*queue))
    {
        *queue=(*queue)->next;
        return;
    }
    else
    {
        printf("Queue is already empty\n");
        return;
    }
}

int front(struct queue* queue)
{
    if(!isempty(queue))
    return queue->data;
    else
    {
        printf("Queue is empty\n");
        return -1;
    }
}

int main()
{
    struct queue* queue=NULL;
    enqueue(&queue,1);
    printf("%d\n",front(queue));
    enqueue(&queue,7);
    printf("%d\n",front(queue));
    enqueue(&queue,5);
    printf("%d\n",front(queue));
    dequeue(&queue);
    printf("%d\n",front(queue));
    dequeue(&queue);
    printf("%d\n",front(queue));
    dequeue(&queue);
    printf("%d\n",front(queue));
    return 0;
}