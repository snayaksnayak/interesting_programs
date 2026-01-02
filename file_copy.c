/* Program for file copy */
/* Date: 02 Apr 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
void main()
{
 FILE *f,*f2;
 int c;
 clrscr();
 f=fopen("26.jpg","rb");
 f2=fopen("b.jpg","wb");
 c=getw(f);
 while(1)
 {
 putw(c,f2);
 if(feof(f))
 {printf("\nend"); break;}
 if(ferror(f)!=0)
 {printf("\nerror"); break;}

 if(c==EOF)
 break;
 c=getw(f);
 }
 fclose(f);
 fclose(f2);
 getch();
}
