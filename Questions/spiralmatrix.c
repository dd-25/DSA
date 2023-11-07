#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int p,q,n;
    scanf("%d %d %d",&p,&q,&n);
    int a[p][q];
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        int r,c,v;
        scanf("%d %d %d",&r,&c,&v);
        a[r][c]=v;
    }
    int I,J;
    int direction;
    scanf("%d %d",&I,&J);
    if(I<p/2)
    {
        if(J<q/2)
        direction=1;
        else
        direction=4;
    }
    else
    {
        if(J<q/2)
        direction=2;
        else
        direction=3;
    }
    int count=0;
    scanf("%d %d",&I,&J);
    int j=0;
    while(1)
    {
        count++;
        if(a[I][J]!=0)
        {
            printf("%d%d%d%d\n",I,J,a[I][J],direction);
            direction=(direction+1)%4;
            for(int i=0;i<=count/2;i++)
            {
                if(direction==1)
                I+=1;
                else if(direction==2)
                J+=1;
                else if(direction==3)
                I-=1;
                else
                J-=1;
            }
            if(I>p-1 || J>q-1 || count==p*q)
            break;
        }
    }
    return 0;
}