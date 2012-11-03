/* Program for creating a log-log graph */
/* Date: 29 Apr 2005 */
/* Author: Srinivas Nayak */
/* Compile using Microsoft VC++ 6.0 */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


//put this code at proper place in a win32 application
//not in console application!

int y=0,x=0,i,max=600;
double p,logarithm[131];

logarithm[0]= 0;
for(i=1,p=1.05;i<=80 && p<=10;++i)
{
logarithm[i]= log10(p);
p+=0.05;
}

for(i=81,p=5.1;i<=130 && p<=10;++i)
{
logarithm[i]= log10(p);
p+=0.1;
}

for (i=1;i<=130;++i)
{
    double temp;

    temp = max*logarithm[i];
    //temp=ceil(max*logarithm[i]);
    //if (temp-0.5 > max*logarithm[i])
    //temp--;


    for(y=0;y<=max-1;y++)
        SetPixel(hdc,(int)temp,y,0xff00ff);

    if (i<81)
    {
    if(i%20==0)
    for(y=max;y<=max+5;y++)
    SetPixel(hdc,(int)temp,y,0x2);
    }
    else
    {
    if(i%10==0)
    for(y=max;y<=max+5;y++)
    SetPixel(hdc,(int)temp,y,0x2);
    }
}

for (i=1;i<=130;++i)
{
    double temp;

    temp = max*logarithm[i];


    for(y=0;y<=max-1;y++)
        SetPixel(hdc,y,(int)temp,0xff00ff);

    if (i<81)
    {
    if(i%20==0)
    for(y=max;y<=max+5;y++)
    SetPixel(hdc,y,(int)temp,0x2);
    }
    else
    {
    if(i%10==0)
    for(y=max;y<=max+5;y++)
    SetPixel(hdc,y,(int)temp,0x2);
    }
}

for(i=0;i<=max+5;++i)
SetPixel(hdc,0,i,0x2);
for(i=0;i<=max+5;++i)
SetPixel(hdc,i,0,0x2);

