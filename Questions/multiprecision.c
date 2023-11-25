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

void insert(struct node **num,int ele)
{
    struct node *temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=ele;
    temp1->next=NULL;
    if(*num==NULL)
    {
        *num=temp1;
        return;
    }
    struct node *temp=*num;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=temp1;
    return;
}

void reverse(struct node **num)
{
    struct node *curr=*num,*next=NULL,*prev=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *num=prev;
    return;
}

void addi(struct node *num1,struct node *num2, struct node **num3)
{
    reverse(&num1);
    reverse(&num2);
    int sum=0,carry=0;
    while(num1!=NULL && num2!=NULL)
    {
        sum=num1->data+num2->data+carry;
        carry=sum/10;
        insert(num3,sum%10);
        num1=num1->next;
        num2=num2->next;
    }
    while(num1!=NULL)
    {
        sum=num1->data+carry;
        carry=sum/10;
        insert(num3,sum%10);
        num1=num1->next;
    }
    while(num2!=NULL)
    {
        sum=num2->data+carry;
        carry=sum/10;
        insert(num3,sum%10);
        num2=num2->next;
    }
    insert(num3,carry);
    reverse(num3);
    reverse(num1);
    reverse(num2);
    return;
}

int countdigi(struct node *num)
{
    struct node *temp=num;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void subt(struct node *num1,struct node *num2, struct node **num3)
{
    if(countdigi(num1)>countdigi(num2))
    {
        reverse(&num1);
        reverse(&num2);
        struct node *temp1=num1;
        struct node *temp2=num2;
        int borrow=0,diff=0;
        while(temp1!=NULL && temp2!=NULL)
        {
            diff=temp1->data-temp2->data;
            if(diff<0)
            {
                diff=temp1->data+borrow*10-temp2->data;
                insert(&num3,diff);
                if(borrow)
                {
                    temp1->data+=1;
                    borrow=0;
                }
                borrow=1;
                temp1->next->data-=borrow;
            }
            else
            {
                insert(&num3,diff);
                borrow=0;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL)
        {
            insert(&num3,temp1->data);
            temp1=temp1->next;
        }
        reverse(&num1);
        reverse(&num2);
        reverse(&num3);
        return;
    }
    else if(countdigi(num1)==countdigi(num2))
    {
        struct node *temp1=num1;
        struct node *temp2=num2;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->data>temp2->data)
            {
                reverse(&num1);
                reverse(&num2);
                temp1=num1;
                temp2=num2;
                int borrow=0,diff=0;
                while(temp1!=NULL && temp2!=NULL)
                {
                    diff=temp1->data-temp2->data;
                    if(diff<0)
                    {
                        diff=temp1->data+borrow*10-temp2->data;
                        insert(&num3,diff);
                        if(borrow)
                        {
                            temp1->data+=1;
                            borrow=0;
                        }
                        borrow=1;
                        temp1->next->data-=1;
                    }
                    else
                    {
                        insert(&num3,diff);
                        borrow=0;
                    }
                    temp1=temp1->next;
                    temp2=temp2->next;
                }
                reverse(&num1);
                reverse(&num2);
                reverse(&num3);
                return;
            }
            else
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
    }
    reverse(&num1);
    reverse(&num2);
    struct node *temp1=num2;
    struct node *temp2=num1;
    int borrow=0,diff=0;
    while(temp1!=NULL && temp2!=NULL)
    {
        diff=temp1->data-temp2->data;
        if(diff<0)
        {
            diff=temp1->data+10-temp2->data;
            insert(&num3,diff);
            if(borrow)
            temp1->data+=borrow;
            borrow=1;
            temp1->next->data-=1;
        }
        else
        {
            if(borrow)
            temp1->data+=borrow;
            insert(&num3,diff);
            borrow=0;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1!=NULL)
    {
        insert(&num3,temp1->data);
        temp1=temp1->next;
    }
    insert(&num3,-1);
    reverse(&num1);
    reverse(&num2);
    reverse(&num3);
    return;
}

// incomplete code
// void multi(struct node *num1,struct node *num2, struct node **num3)
// {
//     return;
// }

// void divis(struct node *num1,struct node *num2, struct node **num3)
// {
//     return;
// }

// void modu(struct node *num1,struct node *num2, struct node **num3)
// {
//     return;
// }

void printnum(struct node *num)
{
    struct node *temp=num;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return;
}

int main()
{
    struct node *num1=NULL;
    struct node *num2=NULL;
    struct node *add=NULL;
    struct node *sub=NULL; // made but is not working 100%
    struct node *mult=NULL; // to be made
    struct node *divi=NULL; // to be made
    struct node *mod=NULL; // to be made

    printf("Enter the 1st number, digit by digit\n");
    while(1)
    {
        int x;
        scanf("%d",&x);
        insert(&num1,x);

        printf("To enter more digits press 'c' otherwise press 'n'\n");
        char c;
        scanf(" %c",&c);
        if(c!='c')
        break;
    }

    printf("Enter the 2nd number, digit by digit\n");
    while(1)
    {
        int x;
        scanf("%d",&x);
        insert(&num2,x);

        printf("To enter more digits press 'c' otherwise press 'n'\n");
        char c;
        scanf(" %c",&c);
        if(c!='c')
        break;
    }

    printnum(num1);
    printnum(num2);

    printf("Addition: ");
    addi(num1,num2,&add);
    printnum(add);

    printf("Subtraction: ");
    subt(num1,num2,&sub);
    printnum(sub);

    // printf("Multiplication: ");
    // multi(num1,num2,&mult);
    // printnum(mult);

    // printf("Quotient: ");
    // divis(num1,num2,&divi);
    // printnum(divi);

    // printf("Remainder: ");
    // modu(num1,num2,&mod);
    // printnum(mod);

    return 0;
}