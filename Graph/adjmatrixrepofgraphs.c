#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

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
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}