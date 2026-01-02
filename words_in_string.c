/* Program to count number of words in a string */
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
   int i=0,count=0,flag=0;
   clrscr();
   printf("enter string:  ");
   c=getchar();
   while(c==' ')
   {c=getchar();continue;}
   while(c!='\n')
   { if(c==' ')
      { flag++; c=getchar();continue;  }
   if(flag>0){ a[i]=' ';i++;}
   a[i]=c;   c=getchar();   i++;   flag=0;
   }
   a[i]='\0';
   i=0;     printf("\n");
   while(a[i]!='\0')
   {putchar(a[i]);i++;}
   i=0;
   while(a[i]!='\0')
   { if(a[i]==' ')
     {count++;}
     i++;
   }
   printf("\n\nfrequency of word  is   %d  ",count+1);
getch();
}