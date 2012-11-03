/* Program to diplay a screen saver */
/* Date: 10 Nov 2002 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */



#include<stdio.h>
#include<conio.h>
#include<graphics.h>
main()
{
	int a=DETECT,b,h=300,k=300,i,d=400,p=300,q=300,e=200;
	initgraph(&a,&b," ");
	cleardevice();

       while(!kbhit())
	{

	setfillstyle(SOLID_FILL,BLACK);
	bar(50,200,60,k);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(50,h,60,480);

	setfillstyle(SOLID_FILL,BLACK);
	bar(70,200,80,p);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(70,q,80,480);

	if(k<d)
	{
	d=400;
	k++;
	h++;
	}

	else
	{ d=300;
	k--;
	h--;
	}

	if(p>e)
	{
	e=200;
	p--;
	q--;
	}


	else
	{ e=300;
	p++;
	q++;
	}

	delay(4);
	}

	getch();
	closegraph();
	return 0;
}


