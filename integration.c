/* Program for finding and showing integration graphically */
/* Date: 18 Dec 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define XAXIS    200
#define YAXIS    240
#define ORIGINX  200
#define ORIGINY  240
#define FUNCTION cos(x)
#define PI       3.142
#define SCALEX   25
#define SCALEY   25
#define DX       0.00005
#define MINX     -5*PI
#define MAXX     5*PI

void main()
{
  int a=DETECT,b,i,j;
  float x,y=0;
  initgraph(&a,&b,"");
  setcolor(2);
  for(i=0;i<=640;i+=20)
  line(i,0,i,479);
  line(639,0,639,479);
   for(j=0;j<=480;j+=20)
  line(0,j,639,j);
  line(0,479,639,479);
    //////////// axis//////
  setcolor(15);
  line(XAXIS,0,XAXIS,479);      // y
  line(0,YAXIS,639,YAXIS);      // x
	 /////////////   FIGURE OF ORIGINAL FUNCTION
//   for(x=MINX;x<=MAXX;x+=DX) {  y=FUNCTION; putpixel(ORIGINX+x*SCALEX,ORIGINY-y*SCALEY,13);  }
	 ///////////
  y=0;  for(x=MINX;x<=MAXX;x+=DX)  {   y=y+DX*(FUNCTION);  putpixel(ORIGINX+x*SCALEX,ORIGINY-y*SCALEY,13);  }
	 ////////////////////
//  y=0;   for(x=0;x<MAXX;x+=DX)    {     y=y+0.0005*(FUNCTION);     putpixel(ORIGINX+x*SCALEX,ORIGINY-y*SCALEY,13);  }
	 /////////////////////////
//  y=0;    for(x=0;x>MINX;x-=DX)    {     y=y+0.0005*(FUNCTION);     putpixel(ORIGINX+x*SCALEX,ORIGINY-y*SCALEY,13);  }
/////////////////////////  DEFINITE INTEGRAL VALUE
//  printf(" %f ",y);
//////////////////////////
  getch();
  closegraph();
}
