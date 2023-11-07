#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct stack
{
    int top;
    struct stack* next;
};

void push(struct stack** stack,int ele)
{
    struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
    temp->top=ele;
    temp->next=*stack;
    *stack=temp;
}

bool isempty(struct stack **stack)
{
    return (*stack==NULL);
}

void pop(struct stack** stack)
{
    if(!isempty(stack))
    (*stack)=(*stack)->next;
    else
    printf("Stack is already empty\n");
}

int top(struct stack** stack)
{
    if(!isempty(stack))
    return (*stack)->top;
    else
    printf("Stack is empty\n");
}

int main()
{
    struct stack* stack=NULL;
    int n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the numbers\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        push(&stack,a[i]);
    }
    while(!isempty(&stack))
    {
        int temp=top(&stack);
        pop(&stack);
        if(isempty(&stack))
        break;
        if(top(&stack)-temp==1 || top(&stack)-temp==-1)
        printf("(%d,%d) ",temp,top(&stack));
    }
    printf("\n");
    return 0;
}