#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

//given a string, find just biggest next string using same chars

char* biggerIsGreater(char* w)
{
    static char s[] = "no answer";
    int len=strlen(w);
    int i;
    int r1,r2;
    for(i=len-1; i>=0; i--)
    {
        //printf("%c ", w[i]);
        if(w[i]>=w[i+1])
            continue;
        else
            break;
    }
    //printf("\n");
    r1=i<0?0:i;

    for(i=len-1; i>=0; i--)
    {
        //printf("%c ", w[i]);
        if(w[i]>w[r1])
            break;
    }
    //printf("\n");
    r2=i<0?0:i;

    if(r2>r1)
    {
        char c=w[r1];
        w[r1]=w[r2];
        w[r2]=c;
        //printf("%s\n", w);
    }
    else
    {
        //printf("no answer\n");
        return s;
    }

    int a=r1+1;
    int b=len-1;
    while(a<=b)
    {
        char k=w[a];
        w[a]=w[b];
        w[b]=k;
        a++;
        b--;
    }

    return w;
}

int main()
{
    //char s[]="abceddccb";
    char s[]="bb";
    printf("%s\n", biggerIsGreater(s));
    return 0;
}

