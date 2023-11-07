#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct queue
{
    int capacity;
    int front;
    int rear;
    int* array;
};

struct queue* create_queue(int capacity)
{
    struct queue* queue;
    queue->capacity=capacity;
    queue->front=0;
    queue->rear=-1;
    queue->array=(int*)malloc(capacity*sizeof(int));
    return queue;
}

bool isfull(struct queue* queue)
{
    return queue->rear==queue->capacity-1;
}

bool isempty(struct queue* queue)
{
    return queue->rear==-1;
}

void enqueue(struct queue* queue, int ele)
{
    if(!isfull(queue))
    queue->array[++queue->rear]=ele;
    else
    {
        printf("Queue is already full\n");
        return;
    }
}

int dequeue(struct queue* queue)
{
    if(!isempty(queue))
    {
        int n=queue->rear--;
        int i=0;
        while(n--)
        {
            queue->array[i]=queue->array[i+1];
            i++;
        }
        return queue->array[queue->front];
    }
    else
    {
        printf("Queue is already empty\n");
        return 0;
    }
}

int front(struct queue* queue)
{
    if(!isempty(queue))
    return queue->array[queue->front];
    else
    {
        printf("Queue is empty\n");
        return -1;
    }
}

int main()
{
    struct queue* queue1=create_queue(3);
    enqueue(queue1,1);
    enqueue(queue1,7);
    enqueue(queue1,5);
    printf("%d\n",front(queue1));
    enqueue(queue1,9);
    printf("%d\n",front(queue1));
    dequeue(queue1);
    printf("%d\n",front(queue1));
    dequeue(queue1);
    printf("%d\n",front(queue1));
    dequeue(queue1);
    printf("%d\n",front(queue1));
    dequeue(queue1);
    return 0;
}