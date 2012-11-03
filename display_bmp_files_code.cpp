/* Program for displaying bmp images */
/* Date: 29 Apr 2005 */
/* Author: Srinivas Nayak */
/* Compile using Microsoft VC++ 6.0 */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */



//Please put this piece of code at proper place in a win32 application
//not in console application!

FILE *fptr;
fptr=fopen("diffcolors.bmp","r");
int a,x,y;

//***********

FILE *storeptr;
storeptr=fopen("store.bmp","w");
fseek(fptr,54l,SEEK_SET);
char ch= fgetc(fptr);
for(;!feof(fptr); ch=fgetc(fptr))
{
fputc(ch,storeptr);
}
fclose(storeptr);

//***********

//***********

storeptr=fopen("store.bmp","r");
for(y=199;y>=0;--y)
{
    for(x=0;x<=199;++x)
    {
    a=fgetc(storeptr);a=a<<8;a=a|fgetc(storeptr);a=a<<8;a=a|fgetc(storeptr);
    SetPixel(hdc,x,y,a);
    }
}
fclose(storeptr);
fclose(fptr);
