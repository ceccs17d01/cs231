/*
 ABIN THOMAS
	S3 D 01
	polynomial multiplication*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int exp,coef;
    struct node *link;
};

void main()
{
    struct node *temp,*head,*head1,*head2,*ptr,*ptr1,*ptr2;
    int e,c,cho,texp,tcoef;

    head=(struct node*)malloc(sizeof(struct node));
    head->exp=0;
    head->coef=0;
    head->link=NULL;

    head1=(struct node*)malloc(sizeof(struct node));
    head1->exp=0;
    head1->coef=0;
    head1->link=NULL;

    head2=(struct node*)malloc(sizeof(struct node));
    head2->exp=0;
    head2->coef=0;
    head2->link=NULL;

    ptr=head1;
    printf("First Polynomial \n");
    do
    {
        printf("Enter coefficient: ");
        scanf("%d",&c);
        printf("Enter exponent: ");
        scanf("%d",&e);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->exp=e;
        temp->coef=c;
        temp->link=NULL;
        ptr->link=temp;
        ptr=ptr->link;
        printf("1. Add more elements\n2. Continue\nEnter choice: ");
        scanf("%d",&cho);
    }while(cho==1);

    printf("\n\nSecond polynomial \n");
    ptr=head2;
    do
    {
        printf("Enter coefficient: ");
        scanf("%d",&c);
        printf("Enter exponent: ");
        scanf("%d",&e);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->exp=e;
        temp->coef=c;
        temp->link=NULL;
        ptr->link=temp;
        ptr=ptr->link;
        printf("1. Add more elements\n2. Continue\nEnter choice: ");
        scanf("%d",&cho);
    }while(cho==1);


    ptr1=head1->link;
    printf("F(p) = ");
    while(ptr1!=NULL)
    {
        printf("%d p%d + ",ptr1->coef,ptr1->exp);
        ptr1=ptr1->link;
    }
    printf("0\n");

    ptr1=head2->link;
    printf("F(q) = ");
    while(ptr1!=NULL)
    {
        printf("%d q%d + ",ptr1->coef,ptr1->exp);
        ptr1=ptr1->link;
    }
    printf("0\n");


    ptr1=head1->link;
    while(ptr1!=NULL)
    {
        ptr2=head2->link;
        while(ptr2!=NULL)
        {
            texp=(ptr1->exp)+(ptr2->exp);
            tcoef=(ptr1->coef)*(ptr2->coef);
            ptr=head->link;
            while(ptr!=NULL)
            {
                if(ptr->exp==texp)
                {
                    ptr->coef+=tcoef;
                    break;
        
                }
                else if(ptr->link==NULL)
                {
                    temp=(struct node*)malloc(sizeof(struct node));
                    ptr->link=temp;
                    temp->exp=texp;
                    temp->coef=tcoef;
                    temp->link=NULL;
                    break;
                
                }
                else if((ptr->link)->exp<texp)
                {
                    temp=(struct node*)malloc(sizeof(struct node));
                    temp->link=ptr->link;
                    ptr->link=temp;
                    temp->exp=texp;
                    temp->coef=tcoef;
                    break;
                }
                ptr=ptr->link;
            }
            if(ptr==NULL)
            {
                temp=(struct node*)malloc(sizeof(struct node));
                head->link=temp;
                temp->coef=tcoef;
                temp->exp=texp;
                temp->link=NULL;
            }
            

            ptr2=ptr2->link;
        }

        ptr1=ptr1->link;
    }
    ptr1=head->link;
    printf("F(r) = ");
    while(ptr1!=NULL)
    {
        printf("%d r%d + ",ptr1->coef,ptr1->exp);
        ptr1=ptr1->link;
    }
    printf("0\n");

}
OUTPUT:
First Polynomial
Enter coefficient: 2
Enter exponent: 2
1. Add more elements
2. Continue
Enter choice: 1
Enter coefficient: 1
Enter exponent: 1
1. Add more elements
2. Continue
Enter choice: 2


Second polynomial
Enter coefficient: 3
Enter exponent: 3
1. Add more elements
2. Continue
Enter choice: 2
F(p) = 2 p2 + 1 p1 + 0
F(q) = 3 q3 + 0
F(r) = 6 r5 + 3 r4 + 0
