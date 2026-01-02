/* Program to operate on a stack */
/* Date: 15 Dec 2002 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */



#include<stdio.h>
#include<conio.h>
#define MAX 5
int i=-1,t=-1,a[MAX];
main()
{       clrscr();
	want();
	return 0;
}

want()
{       int b;
	printf("\n what do you want to do with stack? ");
	printf("\n 1:insert \n");
	printf("\n 2:delete \n");
	printf("\n 3:exit \n");
	scanf("%d",&b);

	if(b==1)insert();
	if(b==2)remov();
	else
	exit(1);
	return 0;
}
insert()
{
	int b;
	if(t<=MAX-2)
	{
	printf("\n INPUT VALUE:");
	t++;
	i++;
	scanf("%d",&a[i]);
	}
	else
	{
	printf("\n sorry! stack full");
	want();
	}

	printf("\n any more 1:yes 2:no ?");
	scanf("%d",&b);
	if(b==1)
	insert();
	else
	want();
     return 0;
}
remov()
{
	int b;
	if(t>-1)
	{
	printf("\n you have %d for delete :",a[i]);
	printf("\n delete? 1:yes 2:no ");
	scanf("%d",&b);
	if(b==1)
	{
	t--;
	i--;
	}
	printf("any more? 1:yes 2:no ");
	scanf("%d",&b);
	if(b==1)
	remov();
	else
	want();
	}
	else
	{
	printf("\n sorry! stack empty ");
	want();
	}
    return 0;
}













