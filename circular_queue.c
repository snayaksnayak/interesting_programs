/* Program for circular queue */
/* Date: 12 Mar 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#define MAX 3
int a[MAX],f=-1,r=-1;
main()
{       clrscr();
	want();
	return 0;
}

want()
{
	int b;
	printf("\n what do you want to do with Q\n");
	printf("1:insert\n");
	printf("2:delete\n");
	printf("3:exit\n");
	scanf("%d",&b);
	if(b==1) insert();
	if(b==2) remov();
	else exit(1);
  return 0;
}

insert()
{  int b;int c;
printf("enter value");scanf("%d",&c);

    if(f==0&&r==MAX-1)
    {  printf("overflow");
       want();
    }
    else if(f==-1)
    {f=0;r=0;a[r]=c;}
    else if(r==MAX-1)
    {r=0;a[r]=c;}
    else
    {r=r+1;
    a[r]=c;}

	printf("\n any more? 1:yes 2:no ");
	scanf("%d",&b);
	if(b==1)
	{
	insert();
	}
	else want();

/*    else
    {
     printf("\n sorry Q full");
     want();
    }      */
  return 0;
}

remov()
{
	int b;
	if(f==-1)
	{printf("underflow");want();}

	printf("\n you have %d for delete.",a[f]);
	printf("\n delete? 1:yes 2:no ");
	scanf("%d",&b);
	if(b==1)
	{
	if(f==r)
	{f=-1;r=-1;}
	else if(f==MAX-1)
	{f=0;}
	else{f++;}
	}
	printf("\n any more? 1:yes 2:no ");
	scanf("%d",&b);
	if(b==1)
	{
	remov();
	}
	else want();

/*    else
    {
     printf("\n sorry Q empty "); f=-1;r=-1;
     want();
    }       */
  return 0;
}










