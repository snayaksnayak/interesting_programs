//find maximum of minimums of a sliding window on an array of numbers

#include<stdio.h> //printf, sprintf
#include<stdlib.h> //malloc, free
#include<string.h> //memset, strcpy
#include<limits.h> //INT_MAX
#include<math.h> //pow

#define MAXNUMS 30

int min(int a[], int s, int e)
{
    printf("min called\n");
    int mn = a[s];
    for(s=s+1; s<=e; s++)
    {
        if(a[s] < mn)
            mn = a[s];
    }
    return mn;
}

int maxof_minsof_slw(int a[], int arrl, int winl)
{
    int s, e;
    int mx = 0;
    int mn;
    for(s=0, e=s+winl-1; e<arrl; s++, e++)
    {
        if(s==0)
        {
            mn = min(a, s, e);
        }
        else
        {
            if(a[e] <= mn)
            {
                mn = a[e];
            }
            else if(a[s-1] > mn)
            {
                //mn remains unchanged
            }
            else //leaving value a[s-1] == mn
            //a[s-1] can't be lesser than mn!
            {
                mn = min(a, s, e);
            }
        }
        if(mn > mx)
            mx = mn;
        printf("min of %d to %d = %d\n", a[s], a[e], mn);
        printf("max so far = %d\n\n", mx);
    }
    return mx;
}

int main()
{
    printf("hello\n");

    int wl=0;
    printf("enter a window length\n");
    scanf("%d", &wl);

    int a[MAXNUMS];
    int n=0;
    printf("enter some numbers\n");
    while(scanf("%d", &a[n])==1)
    {
        n++;
        if(n==MAXNUMS)
            break;
    }

    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    int mx = maxof_minsof_slw(a, n, wl);
    printf("max of minimums of sliding windows = %d\n", mx);

    return 0;
}
