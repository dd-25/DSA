#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

// this function returns the max element from the given set of inputs
int maxr(int a[],int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    if(a[i]>=max)
    max=a[i];
    return max;
}

// this is count sort function
void countsort(int a[],int n,int p)
{
    int output[n];// output array
    int count[10]={0};// this is to note the frequency of digits of corresponding place
    int exp=1;

    for(int i=0;i<p;i++)
    exp*=10; // updating the exponent as place value to compare the corresponding digit

    for(int i=0;i<n;i++)
    count[(a[i]/exp)%10]++;// calculating the frequency of corresponding digits

    // making the frequency cumulative so that sorting and indexing can be done
    for(int i=1;i<10;i++)
    count[i]+=count[i-1];

    for(int i=n-1;i>=0;i--)
    {
        // making the output, sorting the digits based on their corresponding place value
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[((a[i]/exp)%10)]--;// updating the frequency array to maintain indexing
    }

    for(int i=0;i<n;i++)
    a[i]=output[i];// updating the original array

    return;
}

// function to print array
void print(int a[], int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
    return;
}

// function of radix sort using array
void radixsort(int a[],int n)
{
    int max=maxr(a,n);// max number will be returned here

    // this will count the number of maximum digits for which we have to repeat count sort
    for(int i=0;max!=0;i++)
    {
        countsort(a,n,i+1);
        max/=10;
    }

    print(a,n);

    return;
}

int main()
{
    printf("Enter the number of elements you want to sort\n");
    int n;
    scanf("%d",&n);// number of elements

    printf("Enter the elements\n");
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);// input is taken here

    printf("Result of Radix sot is:\n");
    radixsort(a,n);// radixsort function is called

    return 0;
}