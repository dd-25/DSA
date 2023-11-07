#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

struct stack
{
    char top;
    struct stack* next;
};

void push(struct stack** stack,char ele);
void pop(struct stack** stack);
void top(struct stack** stack);

int main()
{
    struct stack* stack1=NULL;
    push(&stack1,'1');
    top(&stack1);
    push(&stack1,'7');
    top(&stack1);
    push(&stack1,'5');
    top(&stack1);
    pop(&stack1);
    top(&stack1);
    pop(&stack1);
    top(&stack1);
    pop(&stack1);
    top(&stack1);
    return 0;
}

void push(struct stack** stack,char ele)
{
    struct stack* temp=NULL;
    temp=(struct stack*)malloc(sizeof(struct stack));
    temp->top=ele;
    temp->next=*stack;
    *stack=temp;
}

void pop(struct stack** stack)
{
    if(*stack!=NULL)
    (*stack)=(*stack)->next;
    else
    printf("Stack is already Empty\n");
}

void top(struct stack** stack)
{
    fflush(stdin);
    if((*stack)!=NULL)
    printf("%c\n",(*stack)->top);
    else
    printf("Stack is Empty\n");
}