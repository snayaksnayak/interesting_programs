/* Program to add two sparse matrix */
/* Date: 01 Feb 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */



#include <stdio.h>
#include <conio.h>
void main()
{
int l,m,i,j,r=0,c=0,cc=0,r1=0,c1=0,a[10][10],s[30][3],s1[30][3],sum[30][3],k=1,non0=0,non01=0,p;
clrscr();
for(p=0;p<2;p++)
{
  if(p==1)  {  r1=r;  c1=c;  }
i=0;j=0;k=1;non0=0;
printf("enter rows: ");
scanf("%d",&r);
printf("enter columns: ");
scanf("%d",&c);
if(p==1)
{  if(r1!=r||c1!=c)
     {  printf("addition not possible:");break;}
}
printf("enter %d elements",r*c);
/*input*/
for(i=0;i<r;i++)
for(j=0;j<c;j++)
scanf("%d",&a[i][j]);
  /*number of non0 element   */
for(i=0;i<r;i++)
for(j=0;j<c;j++)
if(a[i][j]!=0)
non0++;
s[0][0]=r;
s[0][1]=c;
s[0][2]=non0;
for(i=0;i<r;i++)
for(j=0;j<c;j++)
{ 	if(a[i][j]!=0)
	{   s[k][0]=i;	 s[k][1]=j;   s[k][2]=a[i][j]; 	 k++;	 }
}
for(i=0;i<non0+1;i++)
{
for(j=0;j<3;j++)
printf("    %d",s[i][j]);
printf("\n");
}
if(p==0)
{    non01=non0;
     for(i=0;i<non0+1;i++)
	{
	for(j=0;j<3;j++)
	s1[i][j]=s[i][j];    	}
}
} /*Ist for loop end*/
sum[0][0]=r;
sum[0][1]=c;
sum[0][2]=0;
k=1;l=1;m=1 ;
cc=((non01<non0)?non01:non0);
while(k<=non01&&l<=non0)
{
if( (10*s1[k][0]+s1[k][1]) > (10*s[l][0]+s[l][1] ) )
{   sum[m][0]=s[l][0]; sum[m][1]=s[l][1]; sum[m][2]=s[l][2];
    l++; m++;
       continue; }
if( (10*s1[k][0]+s1[k][1]) == (10*s[l][0]+s[l][1] ) )
{   sum[m][0]=s[l][0]; sum[m][1]=s[l][1]; sum[m][2]=s[l][2]+s1[k][2];
    l++; k++; m++;
    continue; }
if( (10*s1[k][0]+s1[k][1]) < (10*s[l][0]+s[l][1]  ))
{   sum[m][0]=s1[k][0]; sum[m][1]=s1[k][1]; sum[m][2]=s1[k][2];
    k++; m++;
    continue; }
} /*while end*/
if(non01<non0)
{    for(;l<=non0;l++)
     { sum[m][0]=s[l][0]; sum[m][1]=s[l][1]; sum[m][2]=s[l][2];
       m++;  }
}
else {
     for(;k<=non01;k++)
     { sum[m][0]=s1[k][0]; sum[m][1]=s1[k][1]; sum[m][2]=s1[k][2];
       m++;  }
}
printf("\n");
for(cc=0;cc<m;cc++)
{
for(i=0;i<3;i++)
printf("    %d",sum[cc][i]);
printf("\n");
}
getch();
}
