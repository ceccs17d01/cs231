/* ABIN THOMAS
   S3 D 01
   Mergesort non-recursive*/
#include<stdio.h>

#define max 25

int main()

{

	int arr[max],temp[max],i,j,k,n,size,x1,y1,x2,y2;

	printf("enter the number of elements : ");

	scanf("%d",&n);

	for(i=0;i<n;i++)

	{

		printf("enter the elements %d :",i+1);

		scanf("%d",&arr[i]);

	}

        for(size=1; size < n; size=size*2 )

	{

		x1=0;

		k=0; 

		while(x1+size<n)

		{

			y1=x1+size-1;

			x2=y1+1;

			y2=x2+size-1;

			if(y2>=n) 

				y2=n-1;

			i=x1;

                        j=x2;

			while(i<=y1&&j<=y2)

			{

				

				if( arr[i]<=arr[j] )

					temp[k++]=arr[i++];

				else

					temp[k++]=arr[j++];

			}

			

			while(i<=y1)

				temp[k++]=arr[i++];

			while(j<=y2)

				temp[k++]=arr[j++];

	                x1=y2+1; 

		}

                for(i=x1; k<n; i++) 

			temp[k++]=arr[i];

                for(i=0;i<n;i++)

			arr[i]=temp[i];

	}

        printf("Sorted list is :\n");

        for( i = 0 ; i<n ; i++)

		printf("%d ", arr[i]);

	

	printf("\n");

	

	return 0;

}

OUTPUT:
enter the number of elements : 5
enter the elements 1 :9
enter the elements 2 :2
enter the elements 3 :3
enter the elements 4 :4
enter the elements 5 :5
Sorted list is :
2 3 4 5 9 

