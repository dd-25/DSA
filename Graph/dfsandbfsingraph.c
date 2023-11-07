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

int** create_graph(int vertices)
{
    int **graph=malloc(vertices*(sizeof(int*)));
    for(int i=0;i<vertices;i++)
    {
        graph[i]=malloc(vertices*sizeof(int));
        for(int j=0;j<vertices;j++)
        graph[i][j]=0;
    }
    return graph;
}

void add_edge(int **graph,int vertice1,int vertice2,int weight)
{
    graph[vertice1][vertice2]=weight;
    graph[vertice2][vertice1]=weight;
    return;
}

void dfs_traverse(int **graph,int vertices,bool *visited,int vertex)
{
    if(visited[vertex]==true)
    return;
    visited[vertex]=true;
    printf("%d\n",vertex);
    for(int i=0;i<vertices;i++)
    if(graph[vertex][i]!=0)
    dfs_traverse(graph,vertices,visited,i);
    return;
}

void bfs_traverse(int **graph,int vertices,bool *visited,int vertex)
{
    if(visited[vertex]==true)
    return;
    struct queue *queue=NULL;
    visited[vertex]=true;
    enqueue(&queue,vertex);
    for(int i=0;i<vertices;i++)
    if(graph[vertex][i]!=0)
    enqueue(&queue,i);
    printf("%d\n",front(queue));
    dequeue(&queue);
    while(!isempty(queue))
    {
        bfs_traverse(graph,vertices,visited,front(queue));
        dequeue(&queue);
    }
    return;
}

int main()
{
    int **graph=create_graph(5);
    add_edge(graph,0,2,1);
    add_edge(graph,2,3,1);
    add_edge(graph,1,2,1);
    add_edge(graph,0,4,1);
    printf(" ");
    for(int i=0;i<5;i++)
    printf(" %d",i);
    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("%d ",i);
        for(int j=0;j<5;j++)
        printf("%d ",graph[i][j]);
        printf("\n");
    }
    bool visited[5];
    for(int i=0;i<5;i++)
    visited[i]=false;
    printf("DFS Traverse:\n");
    dfs_traverse(graph,5,visited,0);
    for(int i=0;i<5;i++)
    visited[i]=false;
    printf("BFS Traverse:\n");
    bfs_traverse(graph,5,visited,0);
    return 0;
}