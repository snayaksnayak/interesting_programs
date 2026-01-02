/* Program to operate on a queue */
/* Date: 15 Dec 2002 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#define MAX 5
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
{
	int b;
    if(r<MAX-1)
    {
	if(f==-1)
	f=0;
	r++;
	printf("\n enter value:");
	scanf("%d",&a[r]);

	printf("\n any more? 1:yes 2:no ");
	scanf("%d",&b);
	if(b==1)
	{
	insert();
	}
	else want();
    }
    else
    {
     printf("\n sorry Q full");
     want();
    }
  return 0;
}

remov()
{
	int b;
    if(f<=MAX-1&&f>-1)
    {
	printf("\n you have %d for delete.",a[f]);
	printf("\n delete? 1:yes 2:no ");
	scanf("%d",&b);
	if(b==1)
	f++;
	printf("\n any more? 1:yes 2:no ");
	scanf("%d",&b);
	if(b==1)
	{
	remov();
	}
	else want();
    }
    else
    {
     printf("\n sorry Q empty "); f=-1;r=-1;
     want();
    }
  return 0;
}










