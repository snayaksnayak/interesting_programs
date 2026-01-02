/* Program to count frequency of a character in a string */
/* Date: 28 Jan 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
void main()
{
   char a[30],c;
   int i=0,count=0;
   clrscr();
   printf("enter string:  ");
   c=getchar();
   while(c!='\n')
   { if(c==' ')
   { c=getchar();continue;  }
   a[i]=c;   c=getchar();   i++;
   }
   a[i]='\0';
   i=0;     printf("\n");
   printf(" enter char for search :  ");
   c=getchar();
   while(a[i]!='\0')
   { if(a[i]==c)
     {count++;}
     i++;
   }
   printf("frequency of   %c   is   %d  ",c,count);
getch();
}