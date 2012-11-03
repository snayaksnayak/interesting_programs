/* Program to diplay day of a date */
/* Date: 12 Nov 2000 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
#include<dos.h>
main()
{
	int a,b,y1,f,g=0,h=0,j,y,d,m=0;  long e,c,i;
	char ch;
	clrscr();
	x:
	printf("ENTER YEAR MONTH DATE IN FORMAT YYYY M(in number) D/DD:: ");
	scanf("%d %d %d",&y,&m,&d);
	a=y-2000;
	b=a/4;
	c=b*366;
	e=((a-b)-1)*365;
	f=c+e;
	g=y%4;
	switch(m)
	{
	case 1 :
	h=0;
	break;

	case 2:
	h=31;
	break;

	case 3:
	h=59;
	break;

	case 4:
	h=90;
	break;

	case 5:
	h=120;break;
	case 6:h=151;break;
	case 7:h=181;break;
	case 8:h=212;break;
	case 9:h=243;break;
	case 10:h=273;break;
	case 11:h=304;break;
	case 12:h=334;break;
	default:
	printf("wrong input");

	exit();
	break;
	}
	if(g==0)
	{
	if(m!=3)
	{
	if(m==1 || m==2)
	h=h;
	else
	h=h+1;
	}
	}

	i=f+h+d;
	j=i%7;
	switch(j)
	{
	case 1:
	printf("\n\tMONDAY\n");
	break;

	case 2:
	printf("\n\tTUESDAY\n");
	break;

	case 3:
	printf("\n\tWEDNESDAY\n");
	break;

	case 4:
	printf("\n\tTHURSDAY\n");
	break;


	case 5:
	printf("\n\tFRIDAY\n");
	break;


	case 6:
	printf("\n\tSATARDAY\n");
	break;


	case 0:
	printf("\n\tSUNDAY\n");
	break;}
	printf("Enter 1 for another day and 2 to exit: ");
	scanf("%d",&y1);
	if(y1==1)
	goto x;
	else
	exit(0);


   getch();

}