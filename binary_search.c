/* Program for binary search */
/* Date: 08 Mar 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[10],s,n,i,mid,start,end,t,j;
void b_search();
void main()
{
      clrscr();
	printf("enter no of items:");
	scanf("%d",&n);
	printf("enter %d values:",n);
	for(i=0;i<n;i++)
	{    scanf("%d",&a[i]);    }
	start=0;
	end=n-1;
    /*************  sorting  ***************/
	for(i=0;i<=n-1;i++)
	{  for(j=0;j<=n-1;j++)
	    {
	      if(a[j]<=a[j+1])
	      { t=a[j];    a[j]=a[j+1];   a[j+1]=t;   }
	      else
	      continue;
	    }
	}
	for(i=0;i<n;i++)
	printf("    %d",a[i]);
     /*********************************************/
	printf("\n which one to search: ");
	scanf("%d",&s);
	b_search();
	getch();
    //	return 0;
}
void  b_search()
{       if(start>end)
	{ printf("\n  not present.  ");      getch();
	exit(0);
	}
	mid=(start+end)/2;
	if(a[mid]==s)
	{     printf("\n it is in %d position.",mid+1);   getch(); exit(0);    }
	if(a[mid]>s)
	{ start=mid+1;
	  b_search();
	}
	if(a[mid]<s)
	{  end=mid-1;
	   b_search();
	}
}

















