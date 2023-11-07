#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

struct stack
{
    int top;
    int capacity;
    char* array;
};

struct stack* create_stack(int capacity);
bool isfull(struct stack* stack);
bool isempty(struct stack* stack);
void push(struct stack* stack,char ele);
int pop(struct stack* stack);
char top(struct stack* stack);

int main()
{
    struct stack* stack1=create_stack(3);
    push(stack1,'1');
    printf("%c\n",top(stack1));
    push(stack1,'7');
    printf("%c\n",top(stack1));
    push(stack1,'5');
    printf("%c\n",top(stack1));
    push(stack1,'9');
    printf("%c\n",top(stack1));
    pop(stack1);
    printf("%c\n",top(stack1));
    pop(stack1);
    printf("%c\n",top(stack1));
    pop(stack1);
    printf("%c\n",top(stack1));
    return 0;
}

struct stack* create_stack(int capacity)
{
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=malloc(stack->capacity*sizeof(char));
    return stack;
}

bool isfull(struct stack* stack)
{
    return (stack->top==stack->capacity-1);
}

bool isempty(struct stack* stack)
{
    return (stack->top==-1);
}

void push(struct stack* stack,char ele)
{
    if(isfull(stack))
    {
        printf("Stack is already full\n");
        return;
    }
    stack->array[++stack->top]=ele;
}

int pop(struct stack* stack)
{
    if(isempty(stack))
    {
        printf("Stack is already empty\n");
        return 0;
    }
    return stack->array[stack->top--];
}

char top(struct stack* stack)
{
    if(isempty(stack))
    {
        printf("Stack is empty");
        return '\0';
    }
    return stack->array[stack->top];
}