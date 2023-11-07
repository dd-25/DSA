#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int a[m][n]={0};
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        int j,l;
        scanf("%d %d",&j,&l);
        a[j][l]=1;
    }
    int count=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1 && a[i][j-1]!=1)
            {
                if(a[i][j+1]==1 && a[i][j+2]==1)
                {
                    int k=j;
                    while(a[i][k]==1 && k<n)
                    {
                        printf("%d%d-",i,k);
                        k++;
                    }
                    printf("\n");
                    count++;
                }
            }
            if(a[i][j]==1 && a[i-1][j]!=1)
            {
                if(a[i+1][j]==1 && a[i+2][j]==1)
                {
                    int k=i;
                    while(a[k][j]==1 && k<m)
                    {
                        printf("%d%d-",k,j);
                        k++;
                    }
                    printf("\n");
                    count++;
                }
            }
            if(a[i][j]==1 && (a[i-1][j-1]!=1 || a[i-1][j+1]!=1))
            {
                if(a[i+1][j+1]==1 && a[i+2][j+2]==1)
                {
                    int k=i,l=j;
                    while(a[k][l]==1 && (k<m && l<n))
                    {
                        printf("%d%d-",k,l);
                        k++;
                        l++;
                    }
                    printf("\n");
                    count++;
                }
                if(a[i+1][j-1]==1 && a[i+2][j-2]==1)
                {
                    int k=i,l=j;
                    while(a[k][l]==1 && (k<m && l>=0))
                    {
                        printf("%d%d-",k,l);
                        k++;
                        l--;
                    }
                    printf("\n");
                    count++;
                }
            }
        }
    }
    printf("%d\n",count);
    return 0;
}