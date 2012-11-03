/* Program for displaying text in a window */
/* Date: 29 Apr 2005 */
/* Author: Srinivas Nayak */
/* Compile using Microsoft VC++ 6.0 */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


// Please put the piece of code at proper place in a win32 application
//not in console application!

FILE *fp;
fp=fopen("abc.txt","r");
int ch;

ch=fgetc(fp);
szHello[0]=ch;

ch=fgetc(fp);
szHello[1]=ch;

szHello[2]='\0';

rt.left=100; rt.top=100; rt.right=250; rt.bottom=120;
DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
