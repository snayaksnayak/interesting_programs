/* Program for reading a floppy disk sectorwise */
/* and printing the 0s and 1s present in it */
/* Date: 31 Mar 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */



/* absread example */

#include <stdio.h>
#include <conio.h>
//#include <process.h>
#include <dos.h>

int main(void)
{
  int i, strt,  sector,k,j,p,q=0;
  char buf[512],ch_out;
  clrscr();
  printf("Insert a diskette into drive A and press any key\n");
  getch();
 printf("sec  ");
 scanf("%d",&p);

  for(k=p;k<=p;k++)
  {
  sector = k;
  if (absread(0, 1, sector, &buf) != 0)
  {
     perror("Disk problem");
     exit(1);
  }
  printf("Read OK\n");
  strt = 0;
  for(j=1;j<=15;j++,q+=32)
  {
  //if(j==1)
  //{
  for (i=q; i<q+32; i++)
  {
    if(i%32==0)
 printf("\n-------------------------------------------------\n");
 if(i==(q+8)||i==(q+11)||i==(q+12)||i==(q+22)||i==(q+24)||i==(q+26)||i==(q+28))
 printf("\n\n");
     ch_out = buf[strt+i];
     printf("[");
     putchar(ch_out);
     printf("]");
    printf("(");
    showbits(ch_out);printf(")---");
  }
 // }
 // else
 // {
 /*   for (i=32; i<64; i++)
  {
   if(i%32==0)
 printf("\n-------------------------------------------------\n");
 if(i==40||i==43||i==44||i==54||i==56||i==58||i==60)
 printf("\n\n");
     ch_out = buf[strt+i];
    printf("[");
    putchar(ch_out);
    printf("]");
    printf("(");
    showbits(ch_out);printf(")---");
  }

  }*/

  getch();
  }
//  printf("\n\n");
//  getch();
  }
//  printf("\n");
//  getch();
  return(0);
}
showbits(char n)
{
   int   i,k,andmask;
   for(i=7;i>=0;i--)
   { andmask=1<<i;
   k=n&andmask;
   k==0?printf("0"):printf("1");
   }
 // printf("%d",n) ;
return 0;
}
