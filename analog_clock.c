/* Program to diplay an analog clock */
/* Date: 07 Dec 2002 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */



#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
main()
{
int gd=DETECT,gm;
int sec,sec1,i,min,hour;
float x1=0.0,x2=0.0,x3=0.0,y1=0.0,y2=0.0,y3=0.0;
struct time t;
initgraph(&gd,&gm,"");
gettime(&t);
sec=t.ti_sec;
sec1=sec;

 circle(250,250,200);
 circle(250,250,210);
 settextstyle(1,0,3);
 outtextxy(240,50,"12");
 outtextxy(340,85,"1");
 outtextxy(400,150,"2");
 outtextxy(420,235,"3");
 outtextxy(400,315,"4");
 outtextxy(340,390,"5");
 outtextxy(245,425,"6");
 outtextxy(140,390,"7");
 outtextxy(85,315,"8");
 outtextxy(65,235,"9");
 outtextxy(85,150,"10");
 outtextxy(138,80,"11");
while(!kbhit())
{
 gettime(&t);
 sec=t.ti_sec;
 min=t.ti_min;
 hour=min/12;
  if(sec==sec1)
  {
  setcolor(BLACK);
  line(250,250,250+y1,250+x1);
  line(250,250,250+y2,250+x2);
  line(250,250,250+y3,250+x3);
   setcolor(WHITE);

      y1=185*cos((3.142/180)*(270+sec*6));
   x1=185*sin((3.142/180)*(270+sec*6));
   x2=140*sin((3.142/180)*(270+min*6));
   y2=140*cos((3.142/180)*(270+min*6));
   x3=100*sin((3.142/180)*(270+hour*6));
   y3=100*cos((3.142/180)*(270+hour*6));
   line(250,250,250+y1,250+x1);
   line(250,250,250+y2,250+x2);
   line(250,250,250+y3,250+x3);
     sec1=sec1+1;
     if(sec1==60)
     sec1=0;
   }
}
}