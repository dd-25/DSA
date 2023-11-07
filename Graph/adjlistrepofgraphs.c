#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct graph
{
    int data;
    int weight;
    struct graph *next;
};

struct graph** create_graph(int vertices)
{
    struct graph** graph=malloc(vertices*sizeof(struct graph*));
    for(int i=0;i<vertices;i++)
    graph[i]=NULL;
    return graph;
}

void add_edge(struct graph **graph,int start,int end,int weight)
{
    struct graph *temp1=graph[start];
    struct graph *temp2=graph[end];
    struct graph *node1=malloc(sizeof(struct graph));
    node1->data=end;
    node1->weight=weight;
    node1->next=NULL;
    struct graph *node2=malloc(sizeof(struct graph));
    node2->data=start;
    node2->weight=weight;
    node2->next=NULL;
    if(temp1==NULL)
    {
        graph[start]=node1;
        if(temp2==NULL)
        {
            graph[end]=node2;
            return;
        }
        while(temp2->next!=NULL)
        temp2=temp2->next;
        temp2->next=node2;
        return;
    }
    while(temp1->next!=NULL)
    temp1=temp1->next;
    temp1->next=node1;
    if(temp2==NULL)
    {
        graph[end]=node2;
        return;
    }
    while(temp2->next!=NULL)
    temp2=temp2->next;
    temp2->next=node2;
    return;
}

int main()
{
    struct graph **graph=create_graph(5);
    add_edge(graph,0,2,1);
    add_edge(graph,2,3,1);
    add_edge(graph,1,2,1);
    add_edge(graph,0,4,1);
    struct graph **temp=graph;
    for(int i=0;i<5;i++)
    {
        printf("%d",i);
        while(temp[i]!=NULL)
        {
            printf("->(%d,%d)",graph[i]->data,graph[i]->weight);
            temp[i]=temp[i]->next;
        }
        printf("\n");
    }
    return 0;
}