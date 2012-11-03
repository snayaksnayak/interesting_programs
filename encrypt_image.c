/* Program for encryption of an image */
/* Date: 30 Mar 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
void main()
{
 FILE *f,*f2;
 int c,i,m,n,a[11],b[11],j;
 clrscr();
 printf("key(ten digits with spaces ;no two digits same)  ");
 for(i=1;i<=10;i++)
 scanf("%d",&a[i]);
 for(i=6,j=1;i<=10;i++,j++)
 b[j]=a[i];
 for(i=1,j=6;i<=5;i++,j++)
 b[j]=a[i];
 for(i=1;i<=10;i++)
 b[i]=b[i]*2;
 f=fopen("nature.jpg","rb");
 f2=fopen("b.jpg","wb");

 for(j=1;j<=10;j++)
 {
 fseek(f,b[j]*1000,0);
 for(i=1;i<=1000;i++)
 {
 c=getw(f);
 putw(c,f2);
 }
 }
 fclose(f);
 fclose(f2);
 getch();
}
