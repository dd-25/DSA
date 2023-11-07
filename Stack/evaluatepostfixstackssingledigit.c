#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct stack
{
    int top;
    int capacity;
    char* array;
};

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

char pop(struct stack* stack)
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
    return '\0';
    return stack->array[stack->top];
}

void evaluate(struct stack* stack,char c)
{
    int a,b;
    if(c=='+')
    {
        a=pop(stack)-'0';
        b=pop(stack)-'0';
        push(stack,(a+b)+'0');
    }
    else if(c=='-')
    {
        a=pop(stack)-'0';
        b=pop(stack)-'0';
        push(stack,(a-b)+'0');
    }
    else if(c=='*')
    {
        a=pop(stack)-'0';
        b=pop(stack)-'0';
        push(stack,(a*b)+'0');
    }
    else if(c=='/')
    {
        a=pop(stack)-'0';
        b=pop(stack)-'0';
        push(stack,(a/b)+'0');
    }
}

void evaluation(char s[])
{
    int n=strlen(s);
    struct stack* stack=create_stack(n);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
        evaluate(stack,s[i]);
        else
        push(stack,s[i]);
    }
    printf("The solution of given string is %c\n",stack->array[stack->top]);
}

int main()
{
    char s[200];
    printf("Enter the string\n");
    gets(s);
    evaluation(s);
    return 0;
}