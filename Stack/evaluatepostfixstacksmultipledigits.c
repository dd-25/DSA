#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

struct stack
{
    int top;
    int capacity;
    int* array;
};

struct stack* create_stack(int capacity)
{
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isfull(struct stack* stack)
{
    return (stack->top == stack->capacity - 1);
}

bool isempty(struct stack* stack)
{
    return (stack->top == -1);
}

void push(struct stack* stack, int ele)
{
    if (isfull(stack))
    {
        printf("Stack is already full\n");
        return;
    }
    stack->array[++stack->top] = ele;
}

int pop(struct stack* stack) {
    if (isempty(stack))
    {
        printf("Stack is already empty\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int top(struct stack* stack)
{
    if (isempty(stack))
    return INT_MIN;
    return stack->array[stack->top];
}

void evaluate(struct stack* stack, char c)
{
    int a, b;
    if (c == '+')
    {
        a = pop(stack);
        b = pop(stack);
        push(stack, (b + a));
    }
    else if (c == '-')
    {
        a = pop(stack);
        b = pop(stack);
        push(stack, (b - a));
    }
    else if (c == '*')
    {
        a = pop(stack);
        b = pop(stack);
        push(stack, (b * a));
    }
    else if (c == '/')
    {
        a = pop(stack);
        b = pop(stack);
        push(stack, (b / a));
    }
}

void evaluation(char s[])
{
    int n = strlen(s);
    struct stack* stack = create_stack(n);
    int num = 0;
    for (int i = 0; s[i]!='\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + (s[i] - '0');
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            evaluate(stack, s[i]);
        }
        else if(s[i]==' ')
        {
            push(stack,num);
            num=0;
        }
    }
    printf("The solution of the given string is %d\n", stack->array[stack->top]);
}

int main()
{
    char s[200];
    printf("Enter the string: ");     // Don't give space after operation, only give space after number
    fgets(s,200,stdin);
    evaluation(s);
    return 0;
}