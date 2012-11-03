/* Program for functions to handle mouse pointer */
/* to be included in other programns */
/* Date: 13 Nov 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<dos.h>
union REGS i,o;
int x1,y1,x2,y2,x,y,button;
int initmouse()
{
	i.x.ax=0;
	int86(0x33,&i,&o);
	return(o.x.ax);
}
void showmouseptr()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}
void restrictmouseptr(int x1,int y1,int x2,int y2)
{
	i.x.ax=7;
	i.x.cx=x1;
	i.x.dx=x2;
	int86(0x33,&i,&o);
	i.x.ax=8;
	i.x.cx=y1;
	i.x.dx=y2;
	int86(0x33,&i,&o);
}
void getmousepos(int *button,int *x,int*y)
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	*button=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
}
void hiemouseptr()
{
	i.x.ax=2;
	int86(0x33,&i,&o);
}
