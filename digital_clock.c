/* Program to diplay a digital clock on screen */
/* Date: 15 Oct 2000 */
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
	int h,m,s,i,j,k;
	clrscr();
	printf("enter the current time(hour minute second)");
	scanf("%d%d%d",&h,&m,&s);
	for(i=0;i<12;i++)
   	for(j=0;j<60;j++)
	for(k=0;k<60;k++)
	 {
	 clrscr();
	 gotoxy(40 , 12);
	 printf("%d:%d:%d",h,m,s);
	 delay(10000000);
	 delay(10000000);
	 delay(300000);
	 if(kbhit()!=0)
	 {
	 exit();
	 }
	 s=s+1;
	 if(s==60)
	 {
	 m=m+1;
	 s=0;

	 }
	 if(m==60)
	 {
	 h=h+1;
	 m=0;
	 }}}
	 ex(int c)
	 {
	 c=getch();
	 if(c==27)
	 exit(0);
	 }


