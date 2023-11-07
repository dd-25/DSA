#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

// this is node definition that is it denotes one term of my expression
struct node
{
    float coe;
    int exp;
    struct node *next;
};

// this is insert function which sort and take only one term of same exponents
void insert(struct node **head, float coe, int exp)
{
    if(coe==0)
    {
        return;
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node)); // allocating memory for new term
    temp->coe = coe;
    temp->exp = exp;
    temp->next = NULL;
    // if head is empty or new exponent is greater than head exponent
    if(*head == NULL || temp->exp > (*head)->exp)
    {
        temp->next = *head;
        *head = temp;
        return;
    }
    struct node *temp1 = *head;
    // this loop will traverse till just greater exponent than new exponent
    while(temp1->next!=NULL && (temp1->next->exp)>=(temp->exp))
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    // if current polynomial function has same exponent then we will simply add the coefficients
    if(temp1->exp == exp)
    {
        temp1->coe += coe;
        return;
    }
    temp1->next = temp;
    return;
}

// this is addition function
void addpoly(struct node *temp1,struct node *temp2, struct node **temp3)
{
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->exp > temp2->exp)
        {
            insert(temp3,temp1->coe,temp1->exp);
            temp1 = temp1->next;
        }
        else if(temp1->exp < temp2->exp)
        {
            insert(temp3,temp2->coe,temp2->exp);
            temp2 = temp2->next;
        }
        else
        {
            if((temp1->coe + temp2->coe)==0)
            continue;
            insert(temp3,(temp1->coe + temp2->coe),temp2->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while(temp1!=NULL)
    {
        insert(temp3,temp1->coe,temp1->exp);
        temp1 = temp1->next;
    }
    while(temp2!=NULL)
    {
        insert(temp3,temp2->coe,temp2->exp);
        temp2 = temp2->next;
    }
    return;
}

// this is subtraction function
void subpoly(struct node *temp1,struct node *temp2, struct node **temp3)
{
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->exp > temp2->exp)
        {
            insert(temp3,temp1->coe,temp1->exp);
            temp1 = temp1->next;
        }
        else if(temp1->exp < temp2->exp)
        {
            insert(temp3,((-1)*temp2->coe),temp2->exp);
            temp2 = temp2->next;
        }
        else
        {
            if((temp1->coe - temp2->coe)==0)
            continue;
            insert(temp3,(temp1->coe - temp2->coe),temp2->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while(temp1!=NULL)
    {
        insert(temp3,temp1->coe,temp1->exp);
        temp1 = temp1->next;
    }
    while(temp2!=NULL)
    {
        insert(temp3,((-1)*temp2->coe),temp2->exp);
        temp2 = temp2->next;
    }
    return;
}

// this is multiplication function
void multpoly(struct node *temp1,struct node *temp2, struct node **temp3)
{
    struct node *temp=temp2;
    while(temp1!=NULL)
    {
        temp2=temp;
        while(temp2!=NULL)
        {
            insert(temp3,(temp1->coe)*(temp2->coe),(temp1->exp)+(temp2->exp));
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return;
}

// this is function to print the polynomial
void printpoly(struct node *head)
{
    struct node *temp=head;
    while(temp != NULL)
    {
        printf("(%.2f)x^(%d)",temp->coe,temp->exp);
        if(temp->next != NULL)
        printf(" + ");
        temp = temp->next;
    }
    printf("\n");
    return;
}

// double pointer concept is used in this code
int main()
{
    struct node *poly1=NULL; // this is first polynomial
    struct node *poly2=NULL; // this is second polynomial
    struct node *polyadd=NULL; // this is addition result
    struct node *polysub=NULL; // this is subtraction result
    struct node *polymult=NULL; // this is multiplication result

    printf("Enter the number of terms for first polynomial\n");
    int n1;
    scanf("%d",&n1);
    printf("Enter the terms in the format (coefficient exponent)\n");
    // following loop is to insert first polynomial
    for(int i=0;i<n1;i++)
    {
        float coe1;
        int exp1;
        scanf("%f %d",&coe1,&exp1);
        insert(&poly1,coe1,exp1);
    }

    printf("Enter the number of terms for second polynomial\n");
    int n2;
    scanf("%d",&n2);
    printf("Enter the terms in the format (coefficient exponent)\n");
    // following loop is to insert second polynomial
    for(int i=0;i<n2;i++)
    {
        float coe2;
        int exp2;
        scanf("%f %d",&coe2,&exp2);
        insert(&poly2,coe2,exp2);
    }

    addpoly(poly1,poly2,&polyadd); // additon of polynomial
    printf("Addition of two polynomial is shown below:\n");
    printpoly(poly1);
    printpoly(poly2);
    printpoly(polyadd);

    subpoly(poly1,poly2,&polysub); // subtraction of polynomial
    printf("\nSubtraction of two polynomial is shown below:\n");
    printpoly(poly1);
    printpoly(poly2);
    printpoly(polysub);

    multpoly(poly1,poly2,&polymult); // multiplication of polynomial
    printf("\nMultiplication of two polynomial is shown below:\n");
    printpoly(poly1);
    printpoly(poly2);
    printpoly(polymult);

    return 0;
}