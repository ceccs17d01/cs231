/* ABIN THOMAS
   S3 D 01
   Insertion Sort*/
#include<stdio.h>
void main() 
{
	int i, j, num, temp, arr[20];
	printf("Enter size of array: ");
	scanf("%d", &num);

	printf("Enter %d elements in arry: \n", num);
	for(i=0; i<num; i++)
		{
		   scanf("%d", &arr[i]);
		}

	for(i=1; i<num; i++)
		{
		   temp=arr[i];
		   j=i-1;
	while((temp<arr[j])&&(j>=0))
		{
	 	   arr[j+1]=arr[j];
		   j=j-1;
		}
	          arr[j+1]=temp;
		}

	printf("After Sorting elements: ");
	for(i=0; i<num; i++)
		{
	  	    printf("%d  ", arr[i]);
		}

}
OUTPUT:
Enter size of array: 4
Enter 4 elements in arry: 
2
43 
345
3
After Sorting elements: 2  3  43  345 
