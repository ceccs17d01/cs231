/*ABIN THOMAS
  S3 D 01
  Binary Search*/
#include<stdio.h>
void main()
{ int f,l,n,mid,a[10],i,s,temp,j;
  printf("Enter no of elements:");
  scanf("%d",&n);
  printf("Enter elements:");
  for(i=0;i<n;i++)
	scanf("%d",&a[i]);
  printf("Enter element to search:");
  scanf("%d",&s);
  for(i=0;i<n;i++)	
	{ for(j=0;j<n;j++)
		{ if(a[i]<a[j])
			{ temp=a[i];
			  a[i]=a[j];
			  a[j]=temp;
			}
		}
	}
  for(i=0;i<n;i++)
	printf("%d \t",a[i]);
  f=0;
  l=n-1;
  mid=(f+l)/2;
  while(f<=l)
	{ if(a[mid]<s)
		f=mid+1;
          else if(a[mid]==s)
		{  printf("Element found:%d",mid+1);
              	   break;
	        }
          else 
		l=mid-1;
          mid=(f+l)/2;
	}

  if (f>l)
      printf("Not found!");
}

OUTPUT:
Enter no of elements:5
Enter elements:4
5
6
3
34
Enter element to search:6
3 	4 	5 	6 	34 	Element found:4
