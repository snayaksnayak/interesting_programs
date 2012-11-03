/* Program for creating 3D graphs */
/* Date: 19 Mar 2004 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define EXP i-3*j
int x(int,int,int), y(int,int,int);
int p,q;
void main()
{
  int a=DETECT,b;
  int m,n;
  int i,j,k;
  initgraph(&a,&b,"");
  // yaxis
  line(320,300,0,485);
  // xaxis
  line(320,300,639,485);
  // zaxis
   line(320,300,320,0);
  /////////////
  for(i=0;i<=150;i+=20)
      for(j=0;j<=150;j+=20)
	for(m=0;m<=10;m++)
	  for(n=0;n<=10;n++)
	   {
	   k=EXP;
	   if(n==10)
	   setcolor(6);
	   else
	   setcolor(15);
	   if(k>0)
	   line(x(i+m,j+n,0),y(i+m,j+n,0),x(i+m,j+n,k),y(i+m,j+n,k));
	    putpixel(x(i+m,j+n,k),y(i+m,j+n,k),4);
	   }
/*  for(i=0;i<=150;i+=20)
      for(j=0;j<=150;j+=20)
	for(m=0;m<=10;m++)
	  for(n=0;n<=10;n++)
	   {
	   k=EXP;
	   if(k>0)
	   putpixel(x(i+m,j+n,k),y(i+m,j+n,k),4);
	   }*/
  getch();
  closegraph();
}
int x(int a, int b, int c)
{
int p;
if(a>b)
{   p=320+(a-b)*cos(0.5237);}
if(a<b)
{  p=320-(b-a)*cos(0.5237);}
if(a==b)
{  p=320+c-c; }
return(p);
}
///////////
int y(int a, int b, int c)
{
int q;
if(a>b)
{ q=300+b+(a-b)*sin(0.5237)-c;}
if(a<b)
{ q=300+a+(b-a)*sin(0.5237)-c;}
if(a==b)
{ q=300+a-c;}
return(q);
}
