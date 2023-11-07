#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

void print_mat(int r,int c,int a[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

int main()
{
    printf("Enter the number of rows:\n");
    int r;
    scanf("%d",&r);
    printf("Enter the number of columns:\n");
    int c;
    scanf("%d",&c);
    int a[r][c];
    printf("Enter the elements rowise\n");
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int x;
            scanf("%d",&x);
            a[i][j]=x;
            if(x!=0)
            count++;
        }
    }
    printf("Original Matrix is\n");
    print_mat(r,c,a);
    int k=0;
    int spm[count][3];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                spm[k][0]=i;
                spm[k][1]=j;
                spm[k][2]=a[i][j];
                k++;
            }
        }
    }
    printf("Sparse matrix is\n");
    print_mat(count,3,spm);
    int temp[count];
    int spmt[count][3];
    for(int i=0;i<count;i++)
    {
        temp[i]=spm[i][0];
    }
    for(int i=0;i<count;i++)
    {
        spmt[i][0]=spm[i][1];
        spmt[i][1]=temp[i];
        spmt[i][2]=spm[i][2];
    }
    printf("Sparse matrix transpose is\n");
    print_mat(count,3,spmt);
    return 0;
}