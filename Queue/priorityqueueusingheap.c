#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//to be edited
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}

void heapify(int *a,int n)
{
    int b=n/2;
    while(b--)
    {
        if(2*b+1>n && a[b]<a[2*b])
        {
            swap(&a[b],&a[2*b]);
        }
        else
        {
            if(a[2*b]>a[2*b+1] && a[b]<a[2*b])
            {
                swap(&a[b],&a[2*b]);
            }
            else if(a[2*b]<a[2*b+1] && a[b]<a[2*b+1])
            {
                swap(&a[b],&a[2*b+1]);
            }
            else
            continue;
        }
    }
    return;
}

void insert(int ele,int *a,int *n)
{
    a[*n]=ele;
    int index=*n;
    while(index)
    {
        if(a[index/2]<a[index])
        {
            swap(&a[index],&a[index/2]);
            index=index/2;
        }
        else
        break;
    }
    (*n)++;
    return;
}

int delete(int *a,int *n)
{
    int d=a[0];
    a[0]==a[*n];
    int index=0;
    int left=2*index+1;
    int right=2*index+2;
    while(right<*n && left<*n)
    {
        if(a[left]>a[right] && a[index]<a[left])
        {
            swap(&a[left],&a[index]);
            index=left;
        }
        else if(a[left]<a[right] && a[index]<a[right])
        {
            swap(&a[right],&a[index]);
            index=right;
        }
        else
        break;
        left=2*index+1;
        right=2*index+2;
    }
    if(left<*n && a[index]<a[left])
    {
        swap(&a[index],&a[left]);
    }
    (*n)--;
    return d;
}

int main()
{
    int a[10]={0};
    int n=0;
    printf("Enter the elements\n");
    for(int i=0;i<7;i++)
    {
        int x;
        scanf("%d",&x);
        insert(x,a,&n);
    }
    return 0;
}