/* Program to diplay calendar */
/* Date: 07 Aug 2001 */
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
	int a,b,y1,f,g=0,h=0,k,j,y,d=1,m=0,p,q,n,r[7][6]={{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
	long e,c,i;
	char ch,x[7][10]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
	clrscr();

	x:
	printf("ENTER YEAR MONTH IN FORMAT YYYY M(in number) :: ");
	scanf("%d %d",&y,&m);
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
	n=1;
	break;

	case 2:
	n=2;
	break;

	case 3:
	n=3;
	break;

	case 4:
	n=4;
	break;


	case 5:
	n=5;
	break;


	case 6:
	n=6;
	break;


	case 0:
	n=0;
	break;}



		switch(m)
		{
		case 1:  h=31;  break;
		case 2: if(g==0) h=29; else h=28; break;
		case 3:  h=31;  break;
		case 4:  h=30;  break;
		case 5:  h=31;  break;
		case 6:  h=30;  break;
		case 7:  h=31;  break;
		case 8:  h=31;  break;
		case 9:  h=30;  break;
		case 10:  h=31;  break;
		case 11:  h=30;  break;
		case 12:  h=31;  break;
		}


		for(p=n;p<7;p++,d++)
		{
		r[p][0]=d;
		}
		for(q=1;q<6;q++)
		{
		for(p=0;p<7;p++)
		{
		r[p][q]=d;
		d++;
		if(d>h)
		break;
		}
		if(d>h)
		break;
		}


		for(p=0;p<7;p++)
		{
		printf("\n");


	for(k=0;k<7;k++)
		{
		gotoxy(2,3+p);if(p==0){ textcolor(4);
	/*	else textcolor(15);*/
		cprintf("%s",x[p]);}
		else{ textcolor(15);
		cprintf("%s",x[p]);}
		}


		printf("\t");


		for(q=0;q<6;q++)
		{
/*		delay(100000);     */
		if(p==0)textcolor(4);
		else textcolor(15);
		if(r[p][q]!=0){gotoxy(8+q*5,3+p);cprintf("%2d",r[p][q]);}        /*FOR SOME DATES IT TAKES GARBAGE VALUE*/
		}


		}
/*	printf("\nEnter 1 for another day and 2 to exit: ");
	scanf("%d",&y1);
	if(y1==1)
	goto x;
	else
	exit(0);  */


   getch();

}







