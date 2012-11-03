/* Program for displaying different colors like color-chooser */
/* Date: 29 Apr 2005 */
/* Author: Srinivas Nayak */
/* Compile using Microsoft VC++ 6.0 */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


//Please this piece of code st the proper place in a win32 application
//not in console application!

int i,lines=0;
long int color=0;
for(lines=50;lines<305;lines++)
    for(i=0;i<255;++i)
    {
        SetPixel(hdc,i,lines,color);
    ++color;
    }
