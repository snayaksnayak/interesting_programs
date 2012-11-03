/* Program for determinant value of a matrix */
/* Date: 29 Jul 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
int b[6][6],a[6][6],sum=0;
void main()
{
     int i,j,n;
     clrscr();
     printf("enter the order :");
     scanf("%d",&n);
     printf("enter %d values:",n*n);
     for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     {
     scanf("%d",&a[i][j]);
     b[i][j]=a[i][j];
     }
  sum= det(b,n);
  printf("\n ans= %d ",sum);
   getch();
}
int det(int r[][6],int n)
{
     int i,j,k,p,q,c[6][6],m,x,y,mid=0;
     if(n==2)
     {
       return(r[0][0]*r[1][1]-r[0][1]*r[1][0]);
     }
      for(i=0;i<n;i++)
      {
	 p=-1; q=0;
	 for(j=1;j<n;j++)
	 {    p++;q=0;
	    for(k=0;k<n;k++)
	    { if(k!=i)
		{
		  c[p][q]=r[j][k];
		    q++;
		}
	     }
	 }
	    mid+=r[0][i]*power((-1),i)*det(c,n-1);
	   for(x=0;x<n-1;x++)
	   {
	   /*
	  printf("\n");
	  for(y=0;y<n-1;y++)
	      {
	    printf(" %d ",c[x][y]);
	      }                     */
	   }
       //	 printf("\n %d ",mid);
     }
     return(mid);
}
power(int a,int b)
{
  if(b==0)
  return(1);
  else
  {
  if(b%2==0)
  return((-1)*a);
  else
  return(a);
  }
}




















