#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff;
	int pow;
	struct node *next;
};
void createnode(int x,int y,struct node **temp)
{
	struct node *r,*z;
	z= *temp;
	if(z==NULL)
	{
		r=(struct node *)malloc(sizeof(struct node));
		r->coeff=x;
		r->pow=y;
		*temp=r;
		r->next=(struct node *)malloc(sizeof(struct node));
		r=r->next;
		r->next=NULL;
	}
	else
	{
		r->coeff=x;
		r->pow=y;
		r->next=(struct node *)malloc(sizeof(struct node));
		r=r->next;
		r->next=NULL;
	}
}
void polyadd(struct node *poly1,struct node *poly2,struct node *poly)
{
	while(poly1->next && poly2->next)
	{
		if(poly->pow > poly2->pow)
		{
			poly->pow=poly1->pow;
			poly->coeff=poly1->coeff;
			poly1=poly1->next;
		}
		else if(poly1->pow<poly->pow)
		{
			
			poly->pow=poly2->pow;
			poly->coeff=poly2->coeff;
			poly2=poly2->next;
		}
		else
		{
			poly->pow=poly1->pow;
			poly->coeff=poly1->coeff+poly2->coeff;
			poly1=poly1->next;
			poly2=poly2->next;
		}
		poly->next=(struct node *)malloc(sizeof(struct node));
		poly=poly->next;
		poly->next=NULL;
	}
	while(poly1->next ||poly2->next)
	{
		if(poly1->next)
		{
			poly->pow=poly1->pow;
			poly->coeff=poly1->coeff;
			poly1=poly1->next;
		}
		if(poly2->next)
		{
			poly->pow=poly2->pow;
			poly->coeff=poly2->coeff;
			poly2=poly2->next;
		}
		poly->next=(struct node *)malloc(sizeof(struct node));
		poly=poly->next;
		poly->next=NULL;
	}
}
void show(struct node *node)
{
	while(node->next!=NULL)
	{
		printf("%dx^%d",node->coeff,node->pow);
		node=node->next;
		if(node->next!=NULL)
			printf("+");
	}
}
int main()
{
	struct node *poly1=NULL,*poly2=NULL,*poly=NULL;
	int m,n,i,p,q,s,t;
	printf("how many terms in polynomial 1: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the coefficient and exponent of the nodes of the first polynomial");
		scanf("%d%d",&p,&q);
		createnode(p,q,&poly1);
	}
	printf("how many terms in poly 2");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("enter the  coefficient and exponent of second polynomial");
		scanf("%d%d",&s,&t);
		createnode(s,t,&poly2);
	}
	printf("first polynomial\n");
	show(poly1);
	printf("second polynomial\n");
	show(poly2);
	poly=(struct node*)malloc(sizeof(struct node));
	polyadd(poly1,poly2,poly);
	printf("\nadded polynomial :");
	show(poly);
	return 0;
}
