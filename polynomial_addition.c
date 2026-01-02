/* Program for polynomial addition */
/* Date: 09 Mar 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */



#include<stdio.h>
#include<conio.h>
main()
{ int a[20],b[20],c[20],i,j,k,m,n,p,check;
clrscr();
printf("how many terms in 1st ?") ;
scanf("%d",&m);
printf("how many terms in 2nd ?") ;
scanf("%d",&n);
printf("enter coff.& exp's of 1st poly");
for(i=1;i<=2*m;i++)
scanf("%d",&a[i]);
printf("enter coff.& exp's of 2nd poly");
for(i=1;i<=2*n;i++)
scanf("%d",&b[i]);
k=1;
for(i=2;i<=2*m;i+=2)
{
    check=0;
    for(j=2;j<=2*n;j+=2)
	{    if(a[i]==b[j])
	     { check++;
	      c[k]=a[i-1]+b[j-1];
	      c[k+1]=a[i];
	      k+=2;
	      b[j]=-100;
	      }

	 }
	if(check==0)
	{ c[k]=a[i-1];c[k+1]=a[i];k+=2;}
}
for(j=2;j<=2*n;j+=2)
{ if(b[j]>-100)
   {c[k]=b[j-1];c[k+1]=b[j]; k+=2;

}
}
k--;
p=k;
for(k=1;k<=p;k+=2)
{printf("+(%dx^%d) ",c[k],c[k+1]);}
getch();  return 0;
}
