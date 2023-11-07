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
    return;
}

// incomplete code
// void subt(struct node *num1,struct node *num2, struct node **num3)
// {
//     reverse(&num1);
//     reverse(&num2);
//     int carry=0,diff=0;
//     while(num1->next!=NULL && num2!=NULL)
//     {
//         diff=num1->data-carry-num2->data;
//         if(diff<0)
//         {
//             diff+=10;
//             carry++;
//             insert(&num3,diff);
//         }
//         else
//         {
//             insert(&num3,diff);
//             carry=0;
//         }
//         num1=num1->next;
//         num2=num2->next;
//     }
//     return;
// }

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
    struct node *sub=NULL; // to be made
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

    // printf("Subtraction: ");
    // subt(num1,num2,&sub);
    // printnum(sub);

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