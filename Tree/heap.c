#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}

void heapify(int *a,int n, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]>a[largest])
    largest=left;
    if(right<n && a[right]>a[largest])
    largest=right;
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
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
    a[0]=a[*n-1];
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
    printf("Heap of first array:\n");
    for(int i=0;i<7;i++)
    {
        printf("%d ",delete(a,&n));
        // printf("%d ",a[i]);
        
    }
    printf("\n");
    printf("Heap of another array:\n");
    int b[15]={0};
    n=15;
    for(int i=1;i<16;i++)
    {
        b[i-1]=i;
    }
    heapify(b,n,1);
    for(int i=0;i<15;i++)
    {
        // printf("%d ",delete(b,&n));
        printf("%d ",b[i]);
    }
    printf("\n");
    return 0;
}