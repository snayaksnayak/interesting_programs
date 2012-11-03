/* Program to diplay a logarithmic graph */
/* Date: 11 Nov 2002 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
main()
{
int a=DETECT,b,i,j;
double p=1.3,q=1.3;
initgraph(&a,&b," ");
cleardevice();
	for(i=0;i<200;)
	{
	i=(int)200*log10(p);
	p+=0.2;
	q=1.3;
	for(j=0;j<200;)
	{j=(int)200*log10(q);
	q+=0.2;
	putpixel(j,i,YELLOW);
	}
	}



getch();
closegraph();
return 0;
}
