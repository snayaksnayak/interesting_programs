/* Program to diplay a mathematical curve */
/* Date: 18 Oct 2002 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
  int a=DETECT,b,g=1,p,q,i=0;
  float x,y,t;
  initgraph(&a,&b," ");
  cleardevice();
  a:
  cleardevice();
  line(0,240,640,240);
  line(320,0,320,480);
  p=320;
  q=240;
//  for(i=0;i<=3.142;i=i+0.0224)
// {
  for(t=0;t<=200;t++)
  {
  x=0.03142*t;
  y=(int)(70*sin(x+0.0224*i));
  q=240-y;
  putpixel(p,q,2);
  p++;
  }
  delay(50);
//  cleardevice();
  i=i+10;
//  g++;
  goto a;
//  }
  getch();
  closegraph();cleardevice();
}
















