#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>

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
void postfix(char* s);
void prefix(char* s);
bool priority(struct stack* stack,char c);

int main()
{
    char s[200];
    printf("Enter the the string\n");
    scanf("%s",s);
    postfix(s);
    prefix(s);
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
    return '\0';
    else
    return stack->array[stack->top];
}

void postfix(char* s)
{
    int n=strlen(s);
    struct stack* stack=create_stack(n);
    char post[n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
        {
            if(!isempty(stack) && priority(stack,s[i]))
            {
                post[j++]=top(stack);
                pop(stack);
                push(stack,s[i]);
            }
            else
            push(stack,s[i]);
        }
        else
        {
            post[j++]=s[i];
        }
    }
    while(!isempty(stack))
    {
        post[j++]=stack->array[stack->top];
        pop(stack);
    }
    post[j]='\0';
    printf("Postfix of given string is: %s\n",post);
}

void prefix(char* s)
{
    int n=strlen(s);
    char pre[n];
    struct stack* stack=create_stack(n);
    strrev(s);
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
        {
            if(!isempty(stack) && priority(stack,s[i]))
            {
                pre[j++]=top(stack);
                pop(stack);
                push(stack,s[i]);
            }
            else
            push(stack,s[i]);
        }
        else
        {
            pre[j++]=s[i];
        }
    }
    while(!isempty(stack))
    {
        pre[j++]=stack->array[stack->top];
        pop(stack);
    }
    pre[j]='\0';
    strrev(pre);
    printf("Prefix of given string is: %s\n",pre);
}

bool priority(struct stack* stack,char c)
{
    if((c=='+' || c=='-') && (stack->array[stack->top]=='*' || stack->array[stack->top]=='/'))
    return 1;
    else
    return 0;
}