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

int main()
{
    printf("Enter the number of characters\n");
    int n;
    scanf("%d",&n);
    printf("Enter the string\n");
    char s[n];
    scanf("%s",s);
    int round=0,curly=0,square=0;
    struct stack* stack=create_stack(100);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            push(stack,s[i]);
            round++;
        }
        else if(s[i]=='{')
        {
            push(stack,s[i]);
            curly++;
        }
        else if(s[i]=='[')
        {
            push(stack,s[i]);
            square++;
        }
        if(s[i]==')' && stack->array[stack->top]=='(')
        {
            round--;
            pop(stack);
        }
        else if(s[i]=='}' && stack->array[stack->top]=='{')
        {
            curly--;
            pop(stack);
        }
        else if(s[i]==']' && stack->array[stack->top]=='[')
        {
            square--;
            pop(stack);
        }
    }
    if(round==0 && curly==0 && square==0 && isempty(stack))
    printf("Balanced\n");
    else
    printf("Not Balanced\n");
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
    printf("%c\n",stack->array[stack->top]);
}