#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct node
{
    int data;
    struct node *next;
};

// this function is to insert element in a linked list
void insert(struct node **head, int ele)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele; // creation of new node
    temp->next=NULL;

    if(*head==NULL) // case for if head is "NULL"
    {
        *head=temp;
        return;
    }

    struct node *temp1=*head;
    while(temp1->next!=NULL) // traversing the linked list till end
    {
        temp1=temp1->next;
    }

    temp1->next=temp; // inserting a node at end
    return;
}

// this function returns the max element from the given set of inputs
int maxr(int *a, int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    if(a[i]>=max)
    max=a[i];
    return max;
}

void radixsort(int *a, int n)
{
    int max=maxr(a,n);
    int digi=0;
    while(max!=0) // finding the maximum number of digits
    {
        digi++;
        max/=10;
    }

    // this is pointer array for linked list
    struct node *p[10]={NULL}; // something like countsort array

    int exp=1;
    for(int j=0;j<digi;j++)
    {
        // inserting array in linked list as per their digits at differnt places
        // "exp" is taking care of the digit's place
        for(int i=0;i<n;i++)
        {
            insert(&p[(a[i]/exp)%10],a[i]); // inserting in linked list with corresponding to digit
        }

        int k=0;
        for(int i=0;i<10;i++) // again inserting data from linked list to array
        {
            while(p[i]!=NULL)
            {
                a[k]=p[i]->data;
                k++;
                p[i]=p[i]->next;
            }
        }
        
        exp*=10; // updating "exp" to take desired digits from the number
    }

// basically we are doing this process to sort digit wise which will ultimately sort given elements
    return;
}

// function to print array
void printarr(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return;
}

int main()
{
    int n; // number of elements we are going to sort
    printf("Enter the number of element(s)\n");
    scanf("%d",&n);

    int a[n]; // input of elements
    printf("Enter the element(s) you want to sort\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    radixsort(a,n); // radix sort function call

    printf("Radix Sort:\n"); // printing radix sorted array
    printarr(a,n);

    return 0;
}

// time complexity of radix sort is: O(n*digi)
// where digi is number of digits in maximum number and n is size of given array